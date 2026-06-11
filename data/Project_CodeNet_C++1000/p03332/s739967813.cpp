#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long

ll mod=998244353;
ll fac[300010];

ll poww( ll x, ll y )
{
    if(y==0) return 1LL;
    ll a = poww( x,y/2 )%mod;
    ll res=a*a;
    res%=mod;
    if( y%2==1 ) res*=x;
    return res%mod;
}

ll inv( ll x )
{
    return poww( x,mod-2 );
}

ll binom( ll n, ll k )
{
    if(k>n) return 0;
    ll br = fac[n];
    ll naz = fac[k]*fac[n-k];
    naz%=mod;
    naz = inv( naz );
    ll ans = (br*naz)%mod;
    return ans;
}

int main()
{
        ios_base::sync_with_stdio(false);
            cin.tie(NULL);

            ll n,a,b,k;
            cin>>n>>a>>b>>k;

            fac[0]=1LL;
            for(ll i=1;i<=n;i++) fac[i]=(fac[i-1]*i)%mod;

            ll res=0;
            for(ll i=0;i<=n;i++){
                ll bb = k - a*i;
                if(bb<0) continue;
                if( bb%b == 0 ){
                    bb/=b;
                    res+=binom( n,i )*binom( n,bb );
                    res%=mod;
                }
            }

            cout<<res<<endl;

            return 0;
}





























