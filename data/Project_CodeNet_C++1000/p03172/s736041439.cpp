#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define endl "\n"
#define pii pair<int,int>
#define pll pair<ll,ll>
typedef long long ll;
#define loop() for(int i=0; i<(); i++)
const int MOD=1e9+7;
int modpow(int x, int n, int m)
{
    if(n==0) return 1;
    ll ans=1;
    while(n>0)
    {
        if(n%2==1) ans=(ans*x)%m;
        x=(x*x)%m;
        n/=2;
    }
    return ans;
}

void solve()
{
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0; i<n; i++) cin>>a[i];
    vector<vector<int>>dp(n+1,vector<int>(k+1,0));
   // fill(dp[1].begin(),dp[1].end(),1);
    for(int i=0; i<=n; i++) dp[i][0]=1;
    
    for(int i=1; i<=n; i++)
    {
        int sum[k+1];
        sum[0]=1;
        for(int j=1; j<=k; j++) sum[j]=(sum[j-1]+dp[i-1][j])%MOD;
        for(int j=1; j<=k; j++)
        {
            int r=min(a[i-1],j);
            dp[i][j]=((sum[j]-sum[j-r]+MOD)%MOD+dp[i-1][j-r])%MOD;
        }
    }
    cout<<dp[n][k]<<endl;

}   

int main(){
	fast
	int t=1;
	//cin>>t;
	while(t--) solve();

}
