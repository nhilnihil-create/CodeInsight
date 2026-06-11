#include <iostream>
#include <vector>
#include <utility>
using namespace std;

vector <pair <int, int> > adj[100001];
int dist[100001];
bool seen[100001] = {};

vector<int> front;
vector<int> back;

int main(){
	ios::sync_with_stdio(false); cin.tie(0);

	int n, u, v, w;
	cin >> n;

	for (int i = 1; i < n; i++){
		cin >> u >> v >> w;
		w &= 1;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}

	seen[1] = 1;
	dist[1] = 0;
	back.push_back(1);
	while (!back.empty()){
		for (int i = 0; i < back.size(); i++){
			u = back[i];
			for (int j = 0; j < adj[u].size(); j++){
				v = adj[u][j].first;
				w = adj[u][j].second;
				if (!seen[v]){
					seen[v] = 1;
					dist[v] = dist[u] ^ w;
					front.push_back(v);
				}
			}
		}
		back.clear();
		front.swap(back);
	}

	for (int i = 1; i <= n; i++) cout << dist[i] << '\n';

	
}