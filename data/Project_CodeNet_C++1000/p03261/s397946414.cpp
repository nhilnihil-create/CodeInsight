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
	map<string, int> cnt;
	string W; cin >> W;
	char last_char = W[W.size() - 1];
	cnt[W]++;
	for (int i  = 1; i < N; ++i) {
		cin >> W;
		if (W[0] != last_char) {
			cout << "No" << endl;
			return;
		}
		if (cnt[W] != 0) {
			cout << "No" << endl;
			return;
		} else {
			cnt[W]++;
		}
		last_char = W[W.size() - 1];
	}
	cout << "Yes" << endl;
	return;
}
int main() {
	solve();
	return 0;
}