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
int n, a[N]; i64 ans;
int main()
{
    n = read(); for(int i = 1; i <= n; ++i) a[i] = read();
    for(int i = 1; i <= n; ++i)
    {
        if(a[i] >= i||a[i+1]-a[i]>1) return puts("-1"), 0;
        if(i < n&&a[i]+1 == a[i+1]) continue; ans += a[i];
    }
    printf("%lld\n", ans);
    return 0;
}
