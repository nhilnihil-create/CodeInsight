// IOI 2021
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ends ' '
#define die(x) return cout << x << endl, 0
#define all(v) v.begin(), v.end()
#define sz(x) (int)(x.size())
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) { cerr << ends << H; debug_out(T...); }
#define debug(...) cerr << "{" << #__VA_ARGS__ << "}:", debug_out(__VA_ARGS__)
typedef long long ll;
typedef pair<int, int> pii;
const ll INF = 1e9;
const ll MOD = 1e9 + 7;

////////////////////////////////////////////////////////////////////

const int N = 1e5 + 5;

vector<int> G[N];
int C[N], M[3];

bool DFS(int v, int c = 1) {
	C[v] = c;
	M[c]++;
	bool f = true;
	for (int u : G[v]) {
		if (C[u] && C[u] != 3 - c) f = false;
		else if (C[u] == 0) f &= DFS(u, 3 - c);
	}
	return f;
}

int main() {

	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int v, u; cin >> v >> u;
		G[v].push_back(u);
		G[u].push_back(v);
	}
	bool f = DFS(1);
	if (!f) die(1LL * n * (n - 1) / 2 - m);
	cout << 1LL * M[1] * M[2] - m << endl;

	return 0;
}
