#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>

using namespace std;

int main(){
	ll N, M;
	
	cin >> N >> M;
	vector<vector<pll> > v(N + 3);

	ll l, r, d;
	while(M--){
		cin >> l >> r >> d;
		v[l].push_back(pll(r, d));
		v[r].push_back(pll(l, -d));
	}

	bool visited[100010];
	ll position[100010];
	memset(visited, 0, sizeof visited);
	bool can = true;

	for(int i = 1; i <= N ; ++i){
		if(!visited[i]){
			queue<ll> q;
			q.push(i);
			position[i] = 0;
			visited[i] = true;
			while(!q.empty()){
				auto idx = q.front(); q.pop();
				for(auto node : v[idx]){
					
					if(!visited[node.first]){
						position[node.first] = position[idx] + node.second;
						q.push(node.first);
						visited[node.first] = true;
					}else if(position[idx] + node.second != position[node.first]){
						can = false;
						goto xgh;
					}
				}
			}
		}
	}

xgh:
	if(can)
		printf("Yes\n");
	else
		printf("No\n");



	return 0;
}
