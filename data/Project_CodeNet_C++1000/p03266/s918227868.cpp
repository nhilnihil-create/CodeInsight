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
	int64 N, K; cin >> N >> K;
	int64 x = N / K;
	if (K % 2 == 0) {
		int64 y = (N / (K / 2)) - x;
		cout << x * x * x + y * y * y << endl;
	} else {
		cout <<  x * x * x << endl;
	}
	return;
}
int main() {
	solve();
	return 0;
}