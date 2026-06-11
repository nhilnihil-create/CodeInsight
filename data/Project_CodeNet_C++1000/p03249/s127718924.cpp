#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <queue>
#define fi first
#define se second
using namespace std;
typedef long long i64;
typedef pair<i64, int> pii;
inline i64 read(int f = 1, i64 x = 0, char ch = ' ')
{
    while(!isdigit(ch = getchar())) if(ch == '-') f = -1;
    while(isdigit(ch)) x = x*10+ch-'0', ch = getchar();
    return f*x;
}
const int N = 1e5+5;
int n, s[N], u[N], v[N]; pii p[N]; i64 sum;
int main()
{
    n = read(); for(int i = 1; i <= n; ++i) p[i].fi = read(), p[i].se = i, s[i] = 1;
    sort(p+1, p+n+1); 
    for(int i = n; i > 1; --i)
    {
        i64 w = p[i].fi-n+s[i]*2; int j = lower_bound(p+1, p+1+n, pii(w, 0))-p;
        if(p[j].fi != w) return puts("-1"), 0; 
        u[i] = p[i].se, v[i] = p[j].se, s[j] += s[i], sum += s[i];
    }
    if(sum != p[1].fi) return puts("-1"), 0;
    for(int i = 2; i <= n; ++i) printf("%d %d\n", u[i], v[i]);
    return 0;
}