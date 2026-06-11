	#include<bits/stdc++.h>
	using namespace std;
	typedef long long ll;
	#define f(i,n) for(ll i=0;i<n;i++)
	#define pb push_back
int mod=1e9+7;
bool vis[100005]={false};
  vector<vector<long long >>dp(100005,vector<long long>(2,1));
  void dfs(vector<int>adj[],int i){
    vis[i]=true;
    for(auto edge:adj[i]){
      if(vis[edge])continue;
      dfs(adj,edge);
      dp[i][0]=(dp[i][0]%mod*(dp[edge][0]%mod+dp[edge][1]%mod+mod)%mod)%mod;
      dp[i][1]=(dp[i][1]%mod*((dp[edge][0]%mod+mod)%mod)%mod);
    }

  }
	int main(){
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
    int n;
    cin>>n;
    // memset(dp,0,sizeof dp);

    vector<int>adj[n];
    for(int i=0;i<n-1;i++){
      int a,b;
      cin>>a>>b;
      a--,b--;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    dfs(adj,0);
    cout<<(dp[0][0]%mod+dp[0][1]%mod)%mod;

		return 0;
	}

