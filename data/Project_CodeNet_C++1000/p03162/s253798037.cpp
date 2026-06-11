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

using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin>>n;
    ll a[n][3];

    fr(i,0,n)
        fr(j,0,3)
            cin>>a[i][j];

    //ll r=1;
    ll dp[n][3]={-1};

    dp[0][0]=a[0][0];
    dp[0][1]=a[0][1];
    dp[0][2]=a[0][2];

    fr(r,1,n)
    {
    for(ll i=0;i<3 && r<n; i++)  // cur_row
    {
        for(ll j=0;j<3;j++) // pre_row
        {
            if(j==i)
                continue;
            dp[r][i]=max(dp[r][i], dp[r-1][j]+a[r][i] );
        }
    }
    }

    /*cout<<nl<<nl;
    fr(i,0,n)
        {
            fr(j,0,3)
            {cout<<dp[i][j]<<" ";}
            cout<<nl;
        }
    */
    cout<< max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]));

return 0;
}

