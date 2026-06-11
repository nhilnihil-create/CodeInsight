#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long mod = 998244353;
const int maxn = 3e5 + 100;
long long fac[maxn],inv[maxn];
ll n,a,b,k;
ll sum=0;
long long q_pow(long long x,long long n)
{
    long long res = 1;
    while(n > 0)
    {
        if(n & 1) res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}

void init()
{
    int i;
    fac[0] = 1;
    for(i = 1;i < maxn;i++)
    {
        fac[i] = (fac[i - 1] * i) % mod;
    }
    inv[maxn - 1] = q_pow(fac[maxn - 1],mod - 2);
    for(i = maxn - 2;i >= 0;i--)
    {
        inv[i] = inv[i + 1] * (i + 1) % mod;
    }
}

long long C(int n,int m)
{
    if(n < m) return 0;
    return fac[n] * inv[m] % mod * inv[n - m] % mod;
}


int main ()
{
    init();
    cin>>n>>a>>b>>k;
    if(k==0)
    {
        puts("1");
        return 0;
    }
    for(register int x=0;x<=n;x++)
    {
        if(k-a*x<0)
            continue;
        if((k-a*x)%b)
            continue;
        ll y=(k-a*x)/b;
        if(y>n)
            continue;
        sum=(sum+C(n,x)%mod*C(n,y)%mod)%mod;
    }
    cout << sum << endl;
    return 0;
}
