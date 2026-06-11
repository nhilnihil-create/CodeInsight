#include<bits/stdc++.h>
using namespace std;
long long M = 1e9+7;
int dp[100001][2];
long long solve1(vector<vector<int>>&Adj, int i,int p){
	//if(p) then iske upr wala black hua hai; else nii
	if(dp[i][p]!=-1) return dp[i][p];
	long long y=1;
	for(int v:Adj[i]) y=(y*solve1(Adj,v,0))%M;
	if(p){
		//i has to be white;
		dp[i][p]=y;
		return y;
	}
	long long x=1; 
	//if i white then y 
	//if i is black then x
	for(int v:Adj[i]) x=(x*solve1(Adj,v,1))%M;
	dp[i][p]=(x+y)%M;
	return dp[i][p];
}

void solve(){
	int n,m,x,y,p,q;
	cin>>n;
	vector<vector<int>>A(n,vector<int>());
	for(int i=1;i<n;i++){
		cin>>x>>y;
		A[x-1].push_back(y-1);
		A[y-1].push_back(x-1);
	}
	vector<vector<int>>Adj(n,vector<int>());
	vector<bool>V(n);
	queue<int>Q;
	Q.push(0);
	V[0]=1;
	while(!Q.empty()){
		int u=Q.front();
		Q.pop();
		for(int v:A[u]){
			if(V[v]) continue;
			V[v]=1;
			Q.push(v);
			Adj[u].push_back(v);
		}
	}
	memset(dp,-1,sizeof(dp));
	cout<<solve1(Adj,0,0);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
}