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
#define mod 1000000007
using namespace std;
int main()
{
    ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    ll n,k;cin>>n>>k;
    ll a[n+1],dp[n+1][k+1];
    memset(dp,0,sizeof(dp));
    fo(i,1,n+1)
        cin>>a[i],dp[i][0]=1;
    dp[0][0]=1;
    fo(i,1,n+1)
    {
        for(ll j=1;j<=k;j++)
        {
            dp[i][j] = (dp[i-1][j]+dp[i][j-1])%mod;
            if(j>a[i])
                dp[i][j]= (dp[i][j] - dp[i-1][j-a[i]-1]+mod)%mod;
            if(dp[i][j]<0)
                dp[i][j]=0;
            //cout << i << " " << j << " " << dp[i][j] << endl;
        }
    }
    cout << dp[n][k];
}

