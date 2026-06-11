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
	double ans = 0.0;
	double rate = 380000.0;
	for (int i = 0; i < N; ++i) {
		double x; cin >> x;
		string u; cin >> u;
		if (u == "JPY") {
			ans += x;
		} else {
			ans += x * rate;
		}
	}
	printf("%.10f\n", ans);
	return;
}
int main() {
	solve();
	return 0;
}