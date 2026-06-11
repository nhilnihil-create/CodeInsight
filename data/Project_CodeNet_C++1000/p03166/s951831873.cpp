#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long int i=0;i<n;i++)
#define foi(i,a,n) for(long long int i=a;i<n;i++)
#define el "\n"

const int INF = 2e9+5;
const int MAX = 1e5+5;
using ll = long long int;
vector<int> vis(MAX,0), dp(MAX,0), deg(MAX,0);
void dfs(vector<vector<int>>& gr, int node, int par){
  	vis[node]=1;
  	for(auto i:gr[node]){
    	if(i!=par){
          dp[i]=max(dp[i],dp[node]+1);
          deg[i]--;
          if(deg[i]<=0)dfs(gr, i, node);
        }
    }
}
void solve(){
	int n,m;cin>>n>>m;
  	vector<vector<int>> gr(n+1);
  	rep(i,m){
    	int x,y;cin>>x>>y;
      	x,y;
      	gr[x].push_back(y);
      	deg[y]++;
    }
	foi(i,1,n+1){
    	if(!vis[i] && deg[i]==0) dfs(gr,i,0);
    }
  	cout<<*max_element(dp.begin(), dp.end());
}

int main(){
  solve();
  return 0;
}