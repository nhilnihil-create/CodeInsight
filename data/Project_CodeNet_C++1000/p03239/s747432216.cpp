#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long int64;
const double PI = 3.14159265358979323846;
const double EPS = 1e-12;
const int INF = 1<<29;
const long long  INFL = 1e18;
const int MOD = 1000000007;
const int MAX = 210000;
const int MAX_NUM = 999999999;
void solve() {
	int N, T; cin >> N >> T;
	vector<pair<int, int>> t(N);
	for (int i = 0; i < N; ++i) {
		int t1, t2; cin >> t1 >> t2;
		t[i] = make_pair(t2, t1);
	}
	sort(t.begin(), t.end());
	int ans = INF;
	for (int i = 0; i < N; ++i) {
		if (t[i].first <= T) {
			ans = min(ans, t[i].second);
		}
	}	
	if (ans == INF) cout << "TLE" << endl;
	else cout << ans << endl;
	return;
}
int main() {
	solve();
	return 0;
}