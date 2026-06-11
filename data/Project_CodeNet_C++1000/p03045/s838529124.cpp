#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
bool vstd[N];
vector<int>v[N];
void dfs(int node){
	if(vstd[node])return ;
	vstd[node]=true;
	for(int u:v[node]){
		dfs(u);
	}
	return;
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n,m;cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y,w;cin>>x>>y>>w;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(!vstd[i]){
			ans++;dfs(i);
		}
	}
	cout<<ans;
}