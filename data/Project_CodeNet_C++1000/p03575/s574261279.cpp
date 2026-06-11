#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

vector<vector<int>> to;
int n;
int m;

bool bfs(int i, int j) {
	vector<int> v(n);
	queue<int> q;
	q.push(i);
	while (!q.empty()) {
		int p = q.front(); q.pop();
		if (v[p]) continue;
		v[p] = 1;
		for (int t: to[p]) {
			if ((p == i && t == j) || (p == j && t == i)) continue;
			q.push(t);
		}
	}
	bool b = false;
	rep(i,n) if (!v[i]) b = true;
	return b;
}

void solve() {
	cin >> n >> m;
	to.resize(n);
	rep(i,m) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		to[a].push_back(b);
		to[b].push_back(a);
	}

	int ans = 0;
	rep(i,n) {
			for (int j: to[i]) {
				if (bfs(i, j)) ans++;
			}
	}
	cout << ans / 2 << endl;
}

int main() {
	solve();
	return 0;
}