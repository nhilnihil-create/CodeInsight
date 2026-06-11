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
	int N, M, X, Y; cin >> N >> M >> X >> Y;
	vector<int> x(N), y(M);
	for (int i = 0; i < N; ++i) cin >> x[i];
	for (int i = 0; i < M; ++i) cin >> y[i];
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	for (int i = X + 1; i <= Y; ++i) {
		if (x[N - 1] < i && i <= y[0]) {
			cout << "No War" << endl;
			return;
		}
	}
	cout << "War" << endl;
	return;
}
int main() {
	solve();
	return 0;
}