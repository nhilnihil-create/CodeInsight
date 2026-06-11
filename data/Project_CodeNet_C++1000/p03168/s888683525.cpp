#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mk make_pair
#define all(v) v.begin(),v.end()
#define fi first
#define se second
#define vl vector<long long int>
#define vvl vector<vector<ll> > 
#define fo(i,a,b) for(int i=a;i<b;i++)
#define rof(i,a,b)  for(int i=b;i>=a;i--)
using namespace std;
ll mod=1000000007;
int main()
{
    ll n;cin>>n;
    double p[n+1];
    fo(i,1,n+1)
        cin>>p[i];
    double dp[n+1][n+1];
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(ll i=1;i<=n;i++)
    {
        for(ll j=0;j<=n;j++)
        {
            if(j==0)
                dp[i][j]=dp[i-1][j]*(1-p[i]);
            else
            {
                dp[i][j] = dp[i-1][j-1]*p[i]+dp[i-1][j]*(1-p[i]);
            }
        }
    }
    double res=0;
    for(ll i=(n+1)/2;i<=n;i++)
        res+=dp[n][i];
    cout << setprecision(10) << res ;
        
}

