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
	int64 A, B, Q; cin >> A >> B >> Q;
	vector<int64> S(A + 2, 0);
	S[0] = -INFL; S[A + 1] = INFL;
	for (int i = 1; i <= A; ++i) {
		cin >> S[i];
	}
	vector<int64> T(B + 2, 0);
	T[0] = -INFL; T[B + 1] = INFL;
	for (int i = 1; i <= B; ++i) {
		cin >> T[i];
	}
	vector<int64> CS(A + 2, 0);
	vector<int64> CT(B + 2, 0);
	for (int i = 1; i <= A; ++i) {
		auto p = lower_bound(all(T), S[i]);
		CS[i] = min(S[i] - p[-1], p[0] - S[i]);
	}
	for (int i = 1; i <= B; ++i) {
		auto p = lower_bound(all(S), T[i]);
		CT[i] = min(T[i] - p[-1], p[0] - T[i]);
	}
	CS[0] = CS[A + 1] = CT[0] = CT[B + 1] = INFL;
	for (int i = 0; i < Q; ++i) {
		int64 X; cin >> X;
		int64 ans = INFL;
		auto P = lower_bound(S.begin(), S.begin() + A + 2, X), Q = lower_bound(T.begin(), T.begin() + B + 2, X);
		ans = min(ans, P[0] - X + CS[P - S.begin()]);
		ans = min(ans, X - P[-1] + CS[P - S.begin() - 1]);
		ans = min(ans, Q[0] - X + CT[Q - T.begin()]);
		ans = min(ans, X - Q[-1] + CT[Q - T.begin()- 1]);
		cout << ans << endl;
	}
	return;
}
int main() {
	solve();
	return 0;
}