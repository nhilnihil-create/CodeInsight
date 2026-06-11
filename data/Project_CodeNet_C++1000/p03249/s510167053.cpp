#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
int N;
ll D[100010];
vector<pair<int,int>> ans;
vector<vector<int>> v(100010);
ll dist[100010] = {0},inf = 1e18;

void dfs(int n){
	for(int i=0;i<v[n].size();i++){
		int s = v[n][i];
		if(dist[s]==inf){
			dist[s] = dist[n]+1;
			dfs(s);
		}
	}
}

int main(){
	cin >> N;
	map<ll,int> m,num;
	priority_queue<ll> Q;
	for(int i=1;i<=N;i++){
		cin >> D[i];
		m[D[i]] = i;
		num[D[i]] = 1;
		Q.push(D[i]);
		dist[i] = inf;
	}
	int count = 0;
	while(count<N-1 && !Q.empty()){
		ll s = Q.top();
		Q.pop();
		ll t = s-(N-2*num[s]);
		if(t<=0) continue;
		if(m.count(t)){
			ans.push_back({m[s],m[t]});
			v[m[s]].push_back(m[t]);
			v[m[t]].push_back(m[s]);
			count++;
			num[t] += num[s];
		}
	}
	dist[1] = 0;
	dfs(1);
	ll sum = 0;
	for(int i=2;i<=N;i++) sum += dist[i];
	if(count!=N-1 || sum!=D[1]) cout << -1 << endl;
	else{
		for(int i=0;i<N-1;i++){
			cout << ans[i].first << " " << ans[i].second << endl;
		}
	}
}