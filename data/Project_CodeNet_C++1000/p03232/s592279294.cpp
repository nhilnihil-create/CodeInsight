#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long

    /// 14 39
    ll w[200010],pref[200010],dp[200010],fact[200010];
    ll mod = 1e9 + 7;

        ll modd(ll x)
    {
        return (x%mod+mod)%mod;
    }

    ll poww( ll x, ll y)
    {
        x = modd(x);
        if( y==0 ) return 1LL;
     //   cout << x << " " << y <<endl;
        ll a=poww(x,y/2)%mod;
        ll ans=(a*a)%mod;
        if(y%2==1)ans*=x;
        ans%=mod;
        return ans%mod;
    }



    ll inv( ll x )
    {
        x=modd(x);
        return poww( x, mod-2 )%mod;
    }

  /*  ll binom( ll br, ll naz )
    {
        if( naz < 0 ) return 0;
        ll brr = fact[br];
        ll nazr = fact[naz]*fact[br-naz];
        nazr%=mod;
        nazr=inv(nazr);
        return brr*nazr;
    }*/
/// 4 57
int main()
{
        ios_base::sync_with_stdio(false);
            cin.tie(NULL);

            ll n;
            cin>>n;
            pref[0]=0;
            for( int i=1;i<=n;i++ ) {
                cin>>w[i];
                pref[i]=modd(pref[i-1]+w[i]);
            }
            fact[0]=1LL;
            fact[1]=1LL;
            for( ll i=2;i<=n;i++ ) fact[i]=( fact[i-1]*i )%mod;
            /// sad racunamo sume svih onih intervala dp-om
            dp[1] = pref[n];
            for( int i=2;i<=n;i++ ){
                    dp[i]=modd(dp[i-1]-(pref[n]-pref[n-i+1]));
             /*   for( int j = i; j<=n;j+=i ){
                    dp[i]+=w[j];
                }
                /// treba oduzeti zadnjih i-1 jer se oni ne pikaju, jer ne postoji taj interval za i
                dp[i]-= ( pref[n]-pref[n-i] );*/
                dp[i]+= modd(pref[n]-pref[i-1]);
                dp[i]=modd( dp[i] );
            /// jos da se oduzme zadnji
            }
     //   cout << " oo "<<endl;
            /// sad kad imamo te duzine, onda gradimo rjesenje nalazeci koliko kojih blokova ima. pazimo na blokove koji nemaju jednu granicu, tj. kojima je granica na -1 ili n+1
            ll res=0;
            for( ll len = 1;len<n;len++ ){
                ll add = modd(fact[n]*( inv( (len+1)*(len+2) ) ));
                add*= modd(2LL*(dp[len]-pref[len] - ( pref[n]-pref[n-len] ) ));
                add=modd(add);
                res+=add;
                res=modd(res);
                add = modd(fact[n]*( inv( len+1 ) ));
                add*=modd( pref[len]+( pref[n]-pref[n-len] ) );
                add=modd(add);
                res+=add;
                res=modd(res);
            }
            res+= modd(pref[n]*fact[n]);  /// ovo je da doda citav interval koji se pozove jednom u svakoj od n!
            res=modd(res);
            cout<<res<<endl;
           // cout << dp[1] << " " << dp[2] << " " << dp[3] <<endl;


            return 0;
}





























