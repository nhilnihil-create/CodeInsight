#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int K; cin >> K;

	vector<P> G[100005];

	for (int i = 0;i < K;i++){
		G[i].push_back(P((i+1)%K, 1));
		G[i].push_back(P((i*10)%K, 0));
	}

	int dist[100005]; fill(dist,dist+K,INT_MAX);
	priority_queue<P, vector<P>, greater<P> > que; // cost, node
	que.push(P(1,1));
	dist[1] = 1;

	while(que.size()){
		P p = que.top(); que.pop();
		int d = p.first; int from = p.second;
		if(dist[from] < d) continue;
		for (int i = 0;i < G[from].size();i++){
			int to = G[from][i].first;
			int cost = G[from][i].second;
			if(dist[to] > d+cost){
				dist[to] = d+cost;
				que.push(P(d+cost, to));
			}
		}
	}

	cout << dist[0] << endl;

	return 0;

}
