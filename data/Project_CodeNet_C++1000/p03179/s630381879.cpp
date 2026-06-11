/*
  KUNAL ANAND
  MNNIT ALLAHABAD
*/  

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<assert.h>
using namespace std;
using namespace __gnu_pbds;
#define debug1(x) cout << # x << " " << x << endl;
#define debug2(x,y) cout << #x << " " << x << " " << #y << " " << y << endl;
#define debug3(x,y,z) cout << #x << " " << x << " " << #y << " " << y << " " << #z << " " << z << endl;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
typedef long long int ll;
const ll INF=1e16;
const ll mod=1e9+7;

ll power(ll x,ll y)
{
    if(y==0)
        return 1;
    ll a=power(x,y/2);
    a=(a*a)%mod;
    if(y%2)
        a=(a*x%mod)%mod;
    return a;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t;
    ll n,q;
    ll i,j,k,a,b,m,c=1,ans1=0,ans2=0,x1,x2,y2,y1,s,mini=LLONG_MAX,idx,ans=0,l;

    cin >> n;

    ll dp[n+1][n+1],presum[n+1][n+1];

    memset(dp,0,sizeof(dp));
    memset(presum,0,sizeof(presum));

    string trouble;

    cin >> trouble;

    dp[1][1]=1;

    presum[1][1]=1;

    for(i=2;i<=n;i++)
    {
        for(j=1;j<=i;j++)
        {
            if(trouble[i-2]=='<')
            {
                dp[i][j]=presum[i-1][j-1];
            }
            else
            {
                dp[i][j]=(presum[i-1][i-1]-presum[i-1][j-1]+mod)%mod;
            }

            presum[i][j]=(presum[i][j-1]+dp[i][j])%mod;

        }
    }

    for(i=1;i<=n;i++)
    {
        ans+=dp[n][i];

        ans%=mod;
    }

    cout << ans << endl;


    return 0;
}    