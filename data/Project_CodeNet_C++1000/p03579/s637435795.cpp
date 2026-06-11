#include <bits/stdc++.h>
#define rep(i,n) for(int i=(0);i<(n);i++)

using namespace std;

typedef long long ll;

int max_N = 100005;

ll N, M;
vector<int> colors(max_N, -1);
vector<vector<int>> g(max_N, vector<int>());

bool dfs(int v, int color){
	colors[v] = color;

	for(int x : g[v]){
		if(colors[x] == color) return false;
		if(colors[x] == -1 && !dfs(x, 1 - color)) return false;
	}

	return true;
}

bool is_bipartite(){
	return dfs(0, 1);
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	rep(i, M){
		int a, b;
		cin >> a >> b;
		g[a-1].push_back(b-1);
		g[b-1].push_back(a-1);
	}

	if(is_bipartite()){
		ll cnt = 0;
		for(int i = 0; i < N; i++){
			if(colors[i] == 1) {
				cnt++;
			}
		}

		cout << (N - cnt) * cnt - M << endl;
	}else{
		cout << N * (N - 1) / 2 - M << endl;
	}
}
