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

void re(char* c);

void pr(long long x);

void pr(const char *x);

void ps();
template<class T, class... Ts> void ps(const T& t, const Ts&... ts);

#ifdef FFDBG

#else
#define dbg(x...) dsfdsfsdfasd
#endif

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#include <cstring>

char s[210000];

void solve()
{
    re(s);
    int n = strlen(s);

    int as = 0;
    long long ans = 0;

    rep(i,0,n) {
        if (s[i] == 'A') as++;
        if (s[i] == 'C') as=0;
        if (s[i] == 'B') {
            if (i+1 < n && s[i+1] == 'C') {
                ans += as;
                i++;
            }
            else as = 0;
        }
    }    

    ps(ans);
}

int main() {

    solve();
}

void re(char* c) { scanf("%s", c); }

void pr(long long x) { printf("%lld", x); }

void pr(const char *x) { printf("%s", x); }

void ps() { pr("\n"); }
template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
    pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
}

