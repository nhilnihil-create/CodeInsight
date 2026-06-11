#include<bits/stdc++.h>
using namespace std;

int dep[200010],dp[200010];
vector<int> e[200010];

int d;

void dfs(int x,int p){
	for(int it:e[x])
		if(it!=p)
			dep[it]=dep[x]+1,dfs(it,x),d=max(d,dp[x]+1+dp[it]),dp[x]=max(dp[x],1+dp[it]);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
		e[u].emplace_back(v);
		e[v].emplace_back(u);
	}
	dfs(1,0);
	if(d%3!=1)	cout<<"First"<<endl;
	else	cout<<"Second"<<endl;	
}
