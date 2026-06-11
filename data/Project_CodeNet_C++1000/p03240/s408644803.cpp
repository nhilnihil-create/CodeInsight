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
	vector<int> x(N), y(N), h(N);
	for (int i = 0; i < N; ++i) {
		cin >> x[i] >> y[i] >> h[i];
	}
	for (int cx = 0; cx <= 100; ++cx) {
		for (int cy = 0; cy <= 100; ++cy) {
			int needH = -1;
			for (int i = 0; i < N; ++i) {
				if (h[i] > 0) {
					int tmpH = h[i] + abs(y[i] - cy) + abs(x[i] - cx);
					if (needH == -1) {
						needH = tmpH;
					} else if (needH != tmpH) {
						needH = -2;
					}
				}
			}
			if (needH == -2) continue;
			for (int i = 0; i < N; ++i) {
				if (h[i] == 0) {
					int tmpH = abs(y[i] - cy) + abs(x[i] - cx);
					if (needH > tmpH) {
						needH = -2;
					}
				}
			}
			if (needH == -2) continue;
			cout << cx << " " << cy << " " << needH << endl;
		}
	}
	return;
}
int main() {
	solve();
	return 0;
}