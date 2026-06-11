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

    ll h,w,k=1,p=1;
    cin>>h>>w;
    char a[h][w];

    fr(i,0,h)
    fr(j,0,w)
    cin>>a[i][j];

    ll dp[h][w];
    dp[0][0]=0;

    fr(i,1,h) //1st column
    {
        if(a[i][0]=='#') k=0;
        dp[i][0]=k;
    }
    fr(i,1,w) //1st row
    {
        if(a[0][i]=='#') p=0;
        dp[0][i]=p;
    }

    fr(i,1,h)
    {
        fr(j,1,w)
        {
            if(a[i][j]=='#')
            {
                dp[i][j]=0; continue;
            }
            dp[i][j] = (dp[i-1][j]%mod) + (dp[i][j-1]%mod) ;
        }
    }
/*
    fr(i,0,h)
    { fr(j,0,w)
        cout<<dp[i][j]<<" ";
      cout<<nl;
    }
*/
    cout<<dp[h-1][w-1] % mod<<nl;
return 0;
}

