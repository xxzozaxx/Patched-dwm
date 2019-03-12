/* See LICENSE file for copyright and license details. */
//      _
//   __| |_      ___ __ ___
//  / _` \ \ /\ / / '_ ` _ \
// | (_| |\ V  V /| | | | | |:Ahmed's dwm config.h:
//  \__,_| \_/\_/ |_| |_| |_|:ahmed_khaledATzohoDoTCoM:
// ┏┓╻╻ ╻
// ┃┗┫╺╋╸
// ╹ ╹╹ ╹


/* appearance */
//static const char *fonts[]       = { "DejaVu Sans Mono:size=10" };
//static const char dmenufont[]    = "monospace:size=10";
static const char *fonts[]         = { "curie" };
static const char dmenufont[]      = "curie";
static const char normbgcolor[]    = "#000000"; // dmenu colors
static const char normfgcolor[]    = "#bbbbbb";
static const char selbgcolor[]     = "#000000";
static const char selfgcolor[]     = "#eeeeee";
static const unsigned int borderpx = 2;   /* border pixel of windows */
static const unsigned int snap     = 32;  /* snap pixel */
static const int showbar           = 1;   /* 0 means no bar */
static const int topbar            = 1;   /* 0 means bottom bar */
static const char col_gray1[]      = "#222222";
static const char col_gray2[]      = "#444444";
static const char col_gray3[]      = "#bbbbbb";
static const char col_gray4[]      = "#eeeeee";
static const char col_cyan[]       = "#005577";
static const char *colors[][3]     = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *  WM_CLASS(STRING) = instance, class
	 *  WM_NAME(STRING) = title
	 *
	 * class            instance     title           tags mask     isfloating   monitor */
	  { "St",           "st",        "dropdown",     0,            1,           -1 },
	  { "st-256color",  "st-256color", "dropdown",     0,            1,           -1 },
	  { "URxvt",        "urxvt",     "dropdown",     0,            1,           -1 },
};

/* layout(s) */
static const float mfact     = 0.60; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[|]=",     tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MOD4     Mod4Mask    /* Super key*/
#define CONTROL  ControlMask /* Control key */
#define SHIFT    ShiftMask   /* Shift key */
#define TAGKEYS(KEY,TAG) \
	{ MOD4,               KEY,      view,           {.ui = 1 << TAG} }, \
	{ MOD4|CONTROL,       KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MOD4|SHIFT,         KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MOD4|CONTROL|SHIFT, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbgcolor, "-sf", selfgcolor, NULL };
static const char *termcmd[]  = { "st", NULL };

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MOD4,                         XK_d,      spawn,          {.v = dmenucmd } },
	{ MOD4,                         XK_Return, spawn,          {.v = termcmd } },
	{ MOD4|SHIFT,                   XK_b,      togglebar,      {0} },

	// Focus jk
	{ MOD4,                         XK_j,      focusstack,     {.i = +1 } },
	{ MOD4,                         XK_k,      focusstack,     {.i = -1 } },

	{ MOD4,                         XK_o,      incnmaster,     {.i = +1 } },
	{ MOD4,                         XK_p,      incnmaster,     {.i = -1 } },
	// Resize master | stack
	{ MOD4,                         XK_h,      setmfact,       {.f = -0.05} },
	{ MOD4,                         XK_l,      setmfact,       {.f = +0.05} },

	// Swap to master and focus
	{ MOD4,                         XK_s,      zoom,           {0} },
	{ MOD4,                         XK_Tab,    view,           {0} },

	// Change layout
	{ MOD4,                         XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MOD4,                         XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MOD4,                         XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MOD4|SHIFT,                   XK_space,  setlayout,      {0} },

	// move current client to float
	{ MOD4,                         XK_space,  togglefloating, {0} },

	{ MOD4,                         XK_0,      view,           {.ui = ~0 } },
	{ MOD4|SHIFT,                   XK_0,      tag,            {.ui = ~0 } },
	{ MOD4,                         XK_comma,  focusmon,       {.i = -1 } },
	{ MOD4,                         XK_period, focusmon,       {.i = +1 } },
	{ MOD4|SHIFT,                   XK_comma,  tagmon,         {.i = -1 } },
	{ MOD4|SHIFT,                   XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MOD4,                         XK_q,      killclient,     {0} },
	{ MOD4|CONTROL,                 XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MOD4,           Button1,        movemouse,      {0} },
	{ ClkClientWin,         MOD4,           Button2,        togglefloating, {0} },
	{ ClkClientWin,         MOD4,           Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MOD4,           Button1,        tag,            {0} },
	{ ClkTagBar,            MOD4,           Button3,        toggletag,      {0} },
};
