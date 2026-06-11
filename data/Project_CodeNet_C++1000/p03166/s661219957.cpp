#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> adj[100001];
bool vis[100001];
void dfs(ll ind, stack<ll>& st){
	vis[ind] = true;
	for(ll i=0;i<adj[ind].size();i++){
		if(!vis[adj[ind][i]])
			dfs(adj[ind][i], st);
	}
	st.push(ind);
}
int main(){
	ll n, m;
	cin>>n>>m;
	ll i;
	ll x, y;
	for(i=0;i<=n;i++){
		adj[i].clear();
		vis[i] = false;
	}
	for(i=0;i<m;i++){
		cin>>x>>y;
		adj[x].push_back(y);
	}
	stack<ll> st;
	for(ll i=1;i<=n;i++){
		if(vis[i]==false)
			dfs(i, st);
	}
	vector<ll> dist(n+1, -1e15);
	dist[st.top()] = 0;
	while(!st.empty()){
		ll ind = st.top();
		st.pop();
		if(dist[ind]!=-1e15){
			for(ll i=0;i<adj[ind].size();i++){
				if(dist[adj[ind][i]]<1+dist[ind])
					dist[adj[ind][i]] = 1+dist[ind];
			}
		}
		else{
			dist[ind] = 0;
			for(ll i=0;i<adj[ind].size();i++){
				if(dist[adj[ind][i]]<1+dist[ind])
					dist[adj[ind][i]] = 1+dist[ind];
			}	
		}
	}
	cout<<*max_element(dist.begin(), dist.end())<<"\n";
	return 0;
}