#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template<typename H> bool chmin(H& v1, const H v2) { if (v1 > v2) { v1 = v2; return true; } return false; }
template<typename H> bool chmax(H& v1, const H v2) { if (v1 < v2) { v1 = v2; return true; } return false; }
template<typename H> void read(H& head) { cin >> head; }
template<typename H, typename ...T> void read(H& head, T& ...tail) { cin >> head; read(tail...); }
template<typename H> void write(H head) { cout << head << '\n'; }
template<typename H, typename ...T> void write(H head, T ...tail) { cout << head << " "; write(tail...); }
template<typename ...T> void die(T ...tok) { write(tok...); exit(0); }

const int inf = 0x3f3f3f3f;
int cost[10] = { 0, 2, 5, 5, 4, 5, 6, 3, 7, 6 };
int dp[100005];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n, m; read(n, m);
	vector<int> digs(m);
	rep(i, 0, m) read(digs[i]);
	sort(all(digs));
	reverse(all(digs));

	rep(i, 0, n) dp[i] = -inf;

	dp[n] = 0;
	for (int i = n - 1; i >= 0; i--) {
		for (int d : digs) if (i + cost[d] <= n)
			chmax(dp[i], dp[i + cost[d]] + 1);
	}

	vector<int> ans;
	for (int i = 0; i < n;) {
		for (int d : digs) if (dp[i] == dp[i + cost[d]] + 1 && i + cost[d] <= n)
		{ 
			ans.push_back(d); i += cost[d]; break; 
		}
	}

	for (int d : ans) cout << d;
	cout << endl;
}
