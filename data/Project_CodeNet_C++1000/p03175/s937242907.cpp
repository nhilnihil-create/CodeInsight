#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define INF 1e18
ll MOD = 1e9+7;
ll a[403];
ll n,K;
vector<int> tr[100001];
ll dp[100001][2];//dp[i][1] colouring the subtree of i with i as black
//P a classic tree dp question
int dfs(int i,int p,int col){
	if(dp[i][col]!=(-1LL)) return dp[i][col];
	if(tr[i].size()==1&&tr[i][0]==p) return 1;
	ll ans=1;
	for(int j:tr[i]){
		if(j!=p){
			if(!col){
				ans*=(dfs(j,i,1)+dfs(j,i,0));
			}
			else ans*=dfs(j,i,0);
			ans = ans%MOD;
		}
	}
	// cout<<ans<<endl;
	return dp[i][col] = ans;
}
int main(){
	cin>>n;
	memset(dp,-1,sizeof dp);
	for(int i=0;i<n-1;i++){
		int a,b;cin>>a>>b;
		a--;b--;
		tr[a].push_back(b);
		tr[b].push_back(a);
	}
	ll ans = (dfs(0,-1,0)+dfs(0,-1,1))%MOD;
	// for(int i=0;i<n;i++){
	// 	cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
	// }
	cout<<ans<<endl;
	return 0;
	//build the tree;
	//proceed to tree-dp
}