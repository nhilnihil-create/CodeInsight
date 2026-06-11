#include<bits/stdc++.h>
using namespace std;
typedef		 long long int    ll;
typedef		vector<ll>      vll;
#define     fi              first
#define     print(v)        for(ll i:v) cout<<i<<ss
#define     se              second
#define		pb              push_back
#define		nn              "\n"
#define		all(p)          p.begin(),p.end()
#define		zz(v)           (ll)v.size()
#define 	S(a)            scanf("%lld",&a)
#define 	SS(a,b)         scanf("%lld %lld",&a,&b)
#define 	SSS(a,b,c)      scanf("%lld %lld %lld",&a,&b,&c)
#define		ss              ' '
#define     pii             pair<ll,ll>
#define		gcd(a,b)        __gcd(a,b)
#define		lcm(a,b)        (a*b)/gcd(a,b)
const double eps = 1e-8;



int main()
{

    ll n;
    cin>>n;
    ll a[n+1][3];

    for(ll i=1; i<=n; i++)
    {
        cin>>a[i][0];
        cin>>a[i][1];
        cin>>a[i][2];

    }
    ll dp[n+1][3];
    memset(dp,0,sizeof(dp));

    for(ll i=1; i<=n; i++)
    {

        for(ll j=0; j<3; j++)
        {
            for(ll k=0; k<3; k++)
            {
                if(j==k)
                    continue;
                dp[i][j]=max(dp[i][j],a[i][j]+dp[i-1][k]);
            }
        }


    }

    cout<<max({dp[n][0],dp[n][1],dp[n][2]})<<nn;


}


/* Final check before submit :

1. array size or integer overflow,like uninitialised 0 index.

2. Think twice,code once.check all possible counter test case.

3. Be careful about corner case! n=1?k=1? something about 0?

4. avoid stupid mistake!complexity(t/m)?precision error?submit same code twice?

5. if got WA than remember that you are missing something common.
   *** Be confident!!! who knows? may be your one step back to AC ***
4. minus mod ans=(ans-k+mod)%mod;

*/




