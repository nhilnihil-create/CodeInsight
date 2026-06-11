#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#include <queue>
#define fi first
#define se second
using namespace std;
typedef long long i64;
inline i64 read(int f = 1, i64 x = 0, char ch = ' ')
{
    while(!isdigit(ch = getchar())) if(ch == '-') f = -1;
    while(isdigit(ch)) x = x*10+ch-'0', ch = getchar();
    return f*x;
}
const int N = 3e5+5, P = 998244353;
int n, ans; i64 k, A, B, fac[N], ifac[N];
i64 inv(int i) { return i == 1?1:P-(P/i)*inv(P%i)%P; }
i64 C(int n, int m) { return fac[n]*ifac[m]%P*ifac[n-m]%P; }
int main()
{
    n = read(), A = read(), B = read(), k = read();
    fac[0] = 1; for(int i = 1; i <= n; ++i) fac[i] = fac[i-1]*i%P;
    ifac[n] = inv(fac[n]); for(int i = n; i; --i) ifac[i-1] = ifac[i]*i%P;
    for(int x = 0; x <= n; ++x)
    {
        if((k-B*x)%A) continue; int y = (k-B*x)/A;
        if(0 <= y&&y <= n) ans = (ans+C(n, x)*C(n, y)%P)%P;
    }
    printf("%d\n", ans);
    return 0;
}