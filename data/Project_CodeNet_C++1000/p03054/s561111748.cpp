#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,n) for(int i=(a); i<(n); i++)
#define all(v) v.begin(), v.end()
#define fi first
#define se second
#define sz(x) int(x.size())
using namespace std;
using ll = long long;
using P = pair<int ,int>;
const int INF = 1001001001;
const int MOD = 1000000007;
template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}

#ifdef _DEBUG
#include "debug.h"
#else
#define debug(...)
#define print(...)
#endif

int main() {
    int h, w, n; cin >> h >> w >> n;
    int sh, sw; cin >> sh >> sw;
    string s,t ; cin >> s >> t;
    int ch = sh;

    bool ok = true;
    rep(i, n) {
        if (s[i]=='U') ch--;
        if (ch<1) ok = false;
        if (t[i]=='D'&&ch<h) ch++;
    }
    debug(ok);
    ch = sh;
        rep(i, n) {
        if (s[i]=='D') ch++;
        if (ch>h) ok = false;
        if (t[i]=='U'&&ch>1) ch--;
    }
    debug(ok);
    int cw = sw;
    rep(i, n) {
        if (s[i]=='L') cw--;
        if (cw<1) ok = false;
        if (t[i]=='R'&&cw<w) cw++;
    }
    debug(ok);
    cw = sw;
    rep(i, n) {
        if (s[i]=='R') cw++;
        if (cw>w) ok = false;
        if (t[i]=='L'&&cw>1) cw--;
    }
    debug(ok);
    if (!ok) puts("NO");
    else puts("YES");
}