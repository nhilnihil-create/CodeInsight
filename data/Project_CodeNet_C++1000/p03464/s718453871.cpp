#include <cstdio>
#include <algorithm>
#include <cctype>
#include <cstring>
using namespace std;
typedef long long int64;
inline int64 read(int f = 1, int64 x = 0, char ch = ' ')
{
    while(!isdigit(ch = getchar())) if(ch == '-') f = -1;
    while(isdigit(ch)) x = x*10+ch-'0', ch = getchar();
    return f*x;
}
const int N = 1e5+5;
int n, a[N];
int64 ans1, ans2;
int main()
{
    n = read();
    for(int i = 1; i <= n; ++i) a[i] = read();
    ans1 = ans2 = 2;
    for(int i = n; i; --i)
    {
        if(ans1%a[i]) ans1 = ans1/a[i]*a[i]+a[i];
        ans2 = ans2/a[i]*a[i]+a[i]-1; 
    }
    if(ans1 < ans2) printf("%lld %lld\n", ans1, ans2);
    else puts("-1");
    return 0;
}