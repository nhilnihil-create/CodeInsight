#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;
typedef long long i64;
inline int read(int f = 1, int x = 0, char ch = ' ')
{
    while(!isdigit(ch = getchar())) if(ch == '-') f = -1;
    while(isdigit(ch)) x = x*10+ch-'0', ch = getchar();
    return f*x;
}
const int N = 2e5+5;
int n, p[N], q[N], vis[N], ans;
int main()
{
    n = read(); for(int i = 1; i <= n; ++i) p[i] = read(), q[p[i]] = i;
    for(int i = 1, j; i <= n; i = j+1)
    {
        for(j = i; j < n&&q[j+1] > q[j]; ++j);
        ans = max(ans, j-i+1);
    }
    printf("%d\n", n-ans);
    return 0;
}