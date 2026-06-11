#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <memory.h>
#include <cmath>
#include <array>

void re(int& x);

void re(char* c);
template<class T, class... Ts> void re(T& t, Ts&... ts);

void pr(const char *x);

void ps();
template<class T, class... Ts> void ps(const T& t, const Ts&... ts);

#ifdef FFDBG

#else
#define dbg(x...) dsfdsfsdfasd
#endif

#define rep(i, a, b) for(int i = a; i < (b); ++i)

int n, a, b, c, d;
char s[210000];
int r[210000];

void solve()
{
    re(n,a,b,c,d,s); a--;b--;c--;d--;

    r[a] = 1;
    rep(i,a+1,n) if (s[i] == '.') {
        r[i] = r[i-1];
        if (i-2 >= 0) r[i] = (r[i] || r[i-2]);
    }   

    if (!r[c] || !r[d]) {
        ps("No");
        return;
    }

    if (c < d) {
        ps("Yes");
        return;
    }

    rep(i,b,d+1) {
        if (i-1 >= 0 && i+1 < n && r[i-1] && r[i] && r[i+1]) {
            ps("Yes");
            return;
        }
    }

    ps("No");
}

int main() {

    solve();
}

void re(int& x) { scanf("%d", &x); }

void re(char* c) { scanf("%s", c); }
template<class T, class... Ts> void re(T& t, Ts&... ts) { 
    re(t); re(ts...); 
}

void pr(const char *x) { printf("%s", x); }

void ps() { pr("\n"); }
template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
    pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
}

