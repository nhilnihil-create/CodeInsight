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

const int N = 2e5 + 5;

bool M[N];
int L[N], R[N], D[N], H[N];
vector<pii> G[N];

void DFS(int v, int w = 0) {
	H[v] = w, M[v] = true;
	for (pii e : G[v]) if (!M[e.first]) DFS(e.first, w + e.second);
}

int main() {

	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> L[i] >> R[i] >> D[i];
		G[L[i]].push_back(make_pair(R[i], D[i]));
		G[R[i]].push_back(make_pair(L[i], -D[i]));
	}
	for (int i = 1; i <= n; i++) if (!M[i]) DFS(i);
	bool flag = true;
	for (int i = 0; i < m; i++) flag &= (H[R[i]] - H[L[i]] == D[i]);
	cout << (flag ? "Yes" : "No") << endl;

	return 0;
}
