#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long LL;
const int N = 100010,mod = 1e9 + 7;
int f[N];
int a[N];
int n;

int qmi(int a,int k)
{
    int res = 1;
    while(k)
    {
        if(k&1) res = (LL)res * a %mod;
        a = (LL)a * a % mod;
        k>>=1;
    }
    return res;
}

void init(int n)
{
    for(int i=1;i<=n;i++) f[i] = qmi(i,mod-2),f[i] = (LL)f[i] + f[i-1] % mod;
}

int main()
{
    scanf("%d",&n);
    init(n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    
    LL ans = 0;
    for(int i=1;i<=n;i++) ans = (ans + (((LL)f[i] + f[n-i+1] - f[1]) % mod + mod) % mod * a[i] % mod)%mod;
    for(int i=1;i<=n;i++) ans = ans * i % mod;
    printf("%lld\n",ans);
    return 0;
}