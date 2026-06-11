#define rep(i, n) for(int i = 0; i < n; i++)
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using P = pair<int, int>;

vector<vector<int>> to(50);

// toが連結であるか否かを判定
bool is_connected(int n) {
	int num_conn = 1;
	vector<bool> visited(n, false);
	queue<int> q;
	q.push(0);
	visited[0] = true;

	while(!q.empty()) {
		int v = q.front();
		q.pop();
		for (auto u : to[v]) {
			if (!visited[u]) {
				visited[u] = true;
				q.push(u);
				num_conn++;
			}
		}
	}

	if (num_conn == n) return true;
	else return false;
}

int main() {
	int n,m;
	cin >> n >> m;
	vector<int> a(m), b(m);
	rep(i,m) {
		cin >> a[i] >> b[i];
		a[i]--, b[i]--;
		to[a[i]].push_back(b[i]);
		to[b[i]].push_back(a[i]);
	}
	int ans = 0;
	rep(i,m) {
		bool connected = true;
		//橋iをグラフから取り除く
		to[a[i]].erase(remove(to[a[i]].begin(), to[a[i]].end(), b[i]), to[a[i]].end());
		to[b[i]].erase(remove(to[b[i]].begin(), to[b[i]].end(), a[i]), to[b[i]].end());

		// 橋iを取り除いたときに連結か否かを判定し、非連結だったらansを1加算
		if (!is_connected(n)) ans++;

		//橋iをグラフに加える
		to[a[i]].push_back(b[i]);
		to[b[i]].push_back(a[i]);
	}
	cout << ans << endl;
	return 0;
}
