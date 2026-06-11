#include<bits/stdc++.h>

#define  ll         long long
#define  llu        unsigned long long
#define  mod        1000000007
#define  pi         ((2.0)*acos(0.0))
#define  pb         push_back
#define  pf         push_front
#define  eb         emplace_back
#define  mp         make_pair
#define  all(x)     (x).begin(),(x).end()
#define  X          first
#define  Y          second

/*loop*/
#define  fr(i,m,n)   for(ll i=m;i<n;++i)

/*output shortcuts*/
#define  nl         "\n"
#define  Yes        cout<<"Yes\n"
#define  yes        cout<<"yes\n"
#define  YES        cout<<"YES\n"
#define  No         cout<<"No\n"
#define  no         cout<<"no\n"
#define  NO         cout<<"NO\n"

ll a[10000000];


using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n,k;
    cin>>n>>k;

    ll a[n];
    fr(i,0,n)
    cin>>a[i];

    ll dp[n];
    dp[n-1]=0;

    for(ll i=n-2; i>=0; i--)
    {
        ll p=LONG_MAX;

        fr(j,1,k+1)
        {
            if(i+j >= n)
                break;
            p = min( (dp[i+j] + abs(a[i]-a[i+j]) ) ,p );
            dp[i]=p;
        }
    }

    cout<<dp[0]<<nl;

return 0;
}


