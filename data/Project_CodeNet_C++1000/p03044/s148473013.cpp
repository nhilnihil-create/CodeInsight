#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
vector<pair<int,int> >v[N];
bool vstd[N];
bool col[N];
void dfs(int node){
	if(vstd[node])return ;
	vstd[node]=true;
	for(auto u:v[node]){
		if(u.second&1)col[u.first]=!col[node];
		else col[u.first]=col[node];
		dfs(u.first);
	}
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n;cin>>n;
	for(int i=0;i<n-1;i++){
		int a,b,w;cin>>a>>b>>w;
		v[a].push_back({b,w});
		v[b].push_back({a,w});
	}
	dfs(1);
	for(int i=1;i<=n;i++){
		cout<<col[i]<<'\n';
	}
	return 0;
}