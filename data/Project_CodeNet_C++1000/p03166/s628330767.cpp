#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pii pair<int,pair<int,char>>
#define sorted(a_1) sort(a_1.begin(),a_1.end())
#define rsorted(a_1) sort(a_1.rbegin(),a_1.rend())
#define t1(a_1) cout<<a_1<<endl;
#define t2(a_1) for(auto it_test : a_1) cout<<it_test<<" ";

int dfs(vector<int>adj[], int parent, vector<int>&visit, vector<int>&dp){
	visit[parent]=1;
	for(auto child : adj[parent]){
		if(!visit[child]){
			dp[parent] = max(dp[parent],1 + dfs(adj,child,visit,dp));
		}
		else{
			dp[parent] = max(dp[parent], 1 + dp[child]);
		}
	}
	return dp[parent];
}
void solve(){
    int n,m;
    cin>>n>>m;
    std::vector<int>adj[n];
    for(int i=0;i<m;i++){
    	int x,y;
    	cin>>x>>y;
    	x--; y--;
    	adj[x].pb(y);
    }
    vector<int>dp(n,0),visit(n,0);
    int ans = 0;
    for(int i=0;i<n;i++)
    if(!visit[i])
    ans = max(ans,dfs(adj,i,visit,dp));
	cout<<ans<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    while(t--){
        solve();
    }

return 0;
}