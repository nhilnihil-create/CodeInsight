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
	int T, A; cin >> T >> A;
	int ans = 0;
	vector<int> H(N);
	vector<int> diff(N);
	int min_diff = 1 << 30;
	for (int i = 0; i < N; ++i) cin >> H[i];	
	for (int i = 0; i < N; ++i) {
		diff[i] = (T * 1000) - (H[i] * 6);
	}
	for (int i = 0; i < N; ++i) {
		int a_diff = abs((A * 1000)  - diff[i]);
		if (a_diff < min_diff) {
			min_diff = a_diff;
			ans = i + 1;
		}
	}
	cout << ans << endl;
	return;
}
int main() {
	solve();
	return 0;
}