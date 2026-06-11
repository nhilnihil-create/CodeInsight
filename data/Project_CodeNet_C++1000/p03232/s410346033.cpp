#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <set>
#include <sstream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int,ll> pil;
typedef pair<int,double> pid;
typedef long double ld;
const int maxn = 1e5+5;
const int inf = 0x3f3f3f3f;
const ll INF = 0x7f7f7f7f7f7f7f7f;
const int mod = 1e9+7;
const int M=1e4+5;
const double PI = acos(-1.0);
const double eps = 1e-5;
ll a[maxn],inv[maxn];
ll fac=1;
ll qpow(ll x,int p)
{
    ll ans = 1;
    while(p)
    {
        if(p&1)
            ans = ans*x%mod;
        x = x*x%mod;
        p>>=1;
    }
    return ans;
}

int main()
{
#ifdef local
    freopen("in.txt","r",stdin);
#endif // local
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        fac = fac*i%mod;
        inv[i] = qpow(i,mod-2);
    }
    for(int i=1; i<=n; i++)
    {
        scanf("%lld",&a[i]);
    }
    for(int i=2; i<=n; i++)
    {
        inv[i] = (inv[i]+inv[i-1])%mod;
    }
    ll ans = 0;
    for(int i=1; i<=n; i++)
    {
        ans = (ans+(a[i]*(inv[i]+inv[n-i+1]-1)%mod)%mod)%mod;
    }
    printf("%lld",ans*fac%mod);
}
