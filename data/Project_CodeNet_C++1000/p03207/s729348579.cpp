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
	int N; cin >> N;
	vector<int> p(N);
	for (int i = 0; i < N; ++i) {
		cin >> p[i];
	}
	sort(p.begin(), p.end());
	int ans = 0;
	for (int i = 0; i < p.size() - 1; ++i) {
		ans += p[i];
	}
	ans += p[p.size() - 1] / 2;
	cout << ans << endl;
	return;
}
int main() {
	solve();
	return 0;
}