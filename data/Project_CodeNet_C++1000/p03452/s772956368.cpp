#include "bits/stdc++.h"
using namespace std;

#define ll long long 
#define ii pair<ll,ll> 
const ll RANGE = 1e9, INF = 1e18;
const int MAXN = 1e5 + 5;

int n, m;
ll pos[MAXN];
bool valid = true;
vector<ii> adj[MAXN];

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; ++i){
		ll u, v, w;
		scanf("%lld %lld %lld", &u, &v, &w);
		adj[u].push_back(ii(v, w));
		adj[v].push_back(ii(u, -w));
	}
	for(int i = 1; i <= n; ++i){
		pos[i] = 1e18;
	}
	for(int i = 1; i <= n; ++i){
		if(pos[i] != INF)
			continue;
		queue<int> q;
		q.push(i);
		pos[i] = 0;
		ll maxVal = 0, minVal = 0;
		while(!q.empty()){
			int top = q.front(); q.pop();

			for(ii j : adj[top]){
				if(pos[j.first] != INF && pos[top]+j.second != pos[j.first]){
					valid = false;
				}else if(pos[j.first] == INF){
					pos[j.first] = pos[top]+j.second;
					maxVal = max(maxVal, pos[j.first]);
					minVal = min(minVal, pos[j.first]);
					q.push(j.first);
				}
			}
		}

		if(maxVal-minVal > RANGE){
			valid = false;
		}
	}

	if(valid)
		printf("Yes\n");
	else
		printf("No\n");
}