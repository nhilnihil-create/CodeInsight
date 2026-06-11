#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;
#define fo(i,s,e_ex) for(i=s;i<e_ex;i++)
#define Fo(i,k,n) for(i=k;k<n?i<=n:i>=n;k<n?i+=1:i-=1)
#define endl '\n'
#define MOD 1000000007//998244353
#define pbb push_back
#define mpp make_pair
#define ff first
#define ss second
#define all(x) x.begin(),x.end()
#define mset(arr,val) memset(arr,val,sizeof(arr))
ll arr[105],dp[105][100005];
void solve(ll caseno){
	ll i,j,n,k;
	cin>>n>>k;
	for(i=1;i<=n;i++) cin>>arr[i];
	fo(i,0,k+1) dp[0][i]=1;
	for(i=1;i<=n;i++){
		for(j=0;j<=k;j++){
			ll mn=j-arr[i]-1;
			dp[i][j]=dp[i-1][j];
			if(mn>=0) dp[i][j]-=dp[i-1][mn];
			dp[i][j]=(dp[i][j]+MOD)%MOD;
		}
		if(i==n){
			cout<<dp[n][k]<<endl;
			return;
		}
		for(j=1;j<=k;j++) {
			dp[i][j]+=dp[i][j-1];
			dp[i][j]%=MOD;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t=1;
	//cin>>t;
	for(ll i=1;i<=t;i++){
		solve(i);
	}
	return 0;
}
