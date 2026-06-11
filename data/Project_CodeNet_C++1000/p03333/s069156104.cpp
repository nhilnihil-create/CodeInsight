#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <set>
using namespace std;
typedef long long i64;
typedef pair<int, int> pii;
inline int read(int f = 1, int x = 0, char ch = ' ')
{
    while(!isdigit(ch = getchar())) if(ch == '-') f = -1;
    while(isdigit(ch)) x = x*10+ch-'0', ch = getchar();
    return f*x;
}
const int N = 1e5+5;
int n, f[2][N]; set<pii> s[2];
i64 move(int &p, int i)
{
    i64 ret = 0; s[0].erase(pii(f[0][i], i)), s[1].erase(pii(f[1][i], i));
    if(f[0][i] <= p&&p <= f[1][i]) return 0;
    else if(p < f[0][i]) ret = f[0][i]-p, p = f[0][i];
    else ret = p-f[1][i], p = f[1][i];
    return ret;
}
i64 solve(int d)
{
    for(int i = 1; i <= n; ++i) s[0].insert(pii(f[0][i], i)), s[1].insert(pii(f[1][i], i));
    i64 ret = 0; int p = 0; set<pii>::iterator it;
    for(int i = 1; i <= n; d ^= 1, ++i) it = d?s[1].begin():--s[0].end(), ret += move(p, it->second);
    return (p>0?p:-p)+ret;
}
int main()
{
    n = read(); for(int i = 1; i <= n; ++i) f[0][i] = read(), f[1][i] = read();
    printf("%lld\n", max(solve(0), solve(1)));
    return 0;
}