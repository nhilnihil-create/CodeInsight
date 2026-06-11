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
	int n, m; cin >> n >> m;
	int k;
	vector<int > cnt(m);
	for (int i = 0; i < n; ++i) {
		cin >> k;
		for (int j = 0; j < k; ++j) {
			int a; cin >> a;
			--a;
			cnt[a]++;
		}
	}
	int ans = 0;
	for (int i = 0; i < cnt.size(); ++i) {
		if (cnt[i] == n) ans++;
	}
	cout << ans << endl;
	return;
}
int main() {
	solve();
	return 0;
}