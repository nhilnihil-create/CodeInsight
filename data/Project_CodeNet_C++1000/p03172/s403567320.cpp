#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ll long long

const int N = 2e5 + 5;
const int MOD = 1e9 + 7;

ll pow(ll a, ll b, ll m)
{
    ll  ans=1;
	while(b)
	{
		if(b&1)
			ans=(ans*a)%m;
		b/=2;
		a=(a*a)%m;
	}
	return ans;
}



int main()
{
	IOS;
	int t=1; //cin>>t;
	while(t--){
	    int n,k; cin>>n>>k;
	    int a[n+1];
	    for(int i=1;i<=n;i++) cin>>a[i];
	    ll dp[n+1][k+1];
	    ll prevprefixsum[k+1];
	    
	    for(int i=0;i<=k;i++) dp[0][i]=0,prevprefixsum[i]=1;
	    for(int i=0;i<=n;i++) dp[i][0]=1;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=k;j++){
                if(j<=a[i]) dp[i][j]=prevprefixsum[j]%MOD;
                else dp[i][j]=prevprefixsum[j]-prevprefixsum[j-a[i]-1];
                dp[i][j]=(dp[i][j]+MOD)%MOD;
            }
            for(int j=1;j<=k;j++)
              prevprefixsum[j]=(dp[i][j]+prevprefixsum[j-1])%MOD;
        }
        //for(int i=0;i<=k;i++) cout<<prevprefixsum[i]<<" "; 
        cout<<dp[n][k];
        /*for(int i=0;i<=n;i++){
            for(int j=0;j<=k;j++){cout<<dp[i][j]<<" ";}
            cout<<endl;}*/
	    cout<<endl;
	}  
}