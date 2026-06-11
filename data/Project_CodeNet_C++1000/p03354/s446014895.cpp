#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
		tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
		tree_order_statistics_node_update> indexed_multiset;

/*
int n , m;
int par[200005];
bool ok[200005];
int getpar(int node){
	if(par[node] == node)
		return node;
	return getpar(par[node]);
}
bool uni(int fnode , int snode){
	int ff = getpar(fnode) ,  ss = getpar(snode);
	if(ff==ss)
		return false;
	par[ff] = ss;
	return true;
}
*/
int n ,m ;
vector<int>vi2;
vector<vector<int>>vi(200005);
bool vis[200005];
int last[200005];
int group ;
void dfs(int node){
	last[node] = group;
	vis[node] = true;
	for(auto it : vi[node]){
		if(!vis[it])dfs(it);
	}
	
}
int main(){
	cin>>n>>m;
	vi2.resize(n);
	for(auto &it : vi2)
		cin>>it;
	for(int i = 0; i <m ; i++){
		int  u , v;
		cin>>u>>v;
		vi[u].push_back(v);
		vi[v].push_back(u);
	}
	for(int i = 1 ; i <=n ; i++){
		if(!vis[i]){
			++group;
			dfs(i);
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		if(vi2[i] == i + 1 ||(last[i+1] == last[vi2[i]])){
			ans++;
		}
	}
	cout<<ans;
	/*
	cin>>n>>m;
	for(int i = 1; i <=n ;i++)
		par[i] = i;
	for(int i = 0; i < m ; i++){
		int u , v;
		cin>>u>>v;
		if(uni(u,v))cout<<u<<" "<<v<<endl;
	}
	*/
   	return 0;	
}
