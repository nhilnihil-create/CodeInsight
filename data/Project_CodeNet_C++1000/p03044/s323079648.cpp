#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ll n;
	cin>>n;
	vector<ll>ans(n+1,-1);
	ans[1]=0;
	vector<vector<pair<ll,ll>>>road(n+1);
	for(int i=0;i<n-1;i++){
		ll u,v,w;
		cin>>u>>v>>w;
		road[u].push_back({v,w%2});
		road[v].push_back({u,w%2});
	}
	queue<ll>que;
	que.push(1);
	while(!que.empty()){
		ll x=que.front();
		que.pop();
		for(pair<ll,ll>p:road[x]){
			if(ans[p.first]!=-1)continue;
			ans[p.first]=(ans[x]+p.second)%2;
			que.push(p.first);
		}
	}
	for(int i=1;i<=n;i++)cout<<ans[i]<<endl;
	return 0;
}