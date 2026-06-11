#include <bits/stdc++.h>
using namespace std; 
int n,m;
vector<int>v[100010];
int low[100010];
int pa[100010];
int dp[100010];
bool vis[100010];
int ans;
void dfs(int pos,int dep){
	low[pos]=dp[pos]=dep;
	vis[pos]=1;
	for(int i=0;i<v[pos].size();i++){
		int to=v[pos][i];
		if(to==pa[pos])continue;
		if(vis[to])low[pos]=min(low[pos],low[to]);
		else{
			pa[to]=pos;
			dfs(to,dep+1);
			low[pos]=min(low[pos],low[to]);
		}
	}
}
set<int>s;
int main() {
    //freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		a--;b--;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(0,0);
	for(int i=0;i<n;i++){
		if(low[i]==dp[i])ans++;
		//else s.insert(low[i]);
	}
	cout<<ans-1<<endl;
    return 0; 
}/*
7 7
1 3
2 7
3 4
4 5
4 6
5 6
6 7
*/