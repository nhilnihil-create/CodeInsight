#include <cstring>
#include <algorithm>
#include <cctype>
#include <cstdio>
#include <ctime>
#include <vector>
#include <cassert>
typedef long long i64;
using namespace std;
inline int read(int f = 1, int x = 0, char ch = ' ')
{
    while(!isdigit(ch = getchar())) if(ch == '-') f = -1;
    while(isdigit(ch)) x = x*10+ch-'0', ch = getchar();
    return f*x;
}
const int N = 1e5+5;
int n, k, c[N]; i64 ans;
int main()
{   
    n = read(), k = read(); for(int i = 1; i <= n; ++i) ++c[i%k];
    ans = c[0]+3*c[0]*(c[0]-1ll)+c[0]*(c[0]-1ll)*(c[0]-2ll);
    if(~k&1) ans += c[k/2]+3*c[k/2]*(c[k/2]-1ll)+c[k/2]*(c[k/2]-1ll)*(c[k/2]-2ll);
    printf("%lld\n", ans);
    return 0;
}