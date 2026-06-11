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
//最小公約数
int gcd(int a, int b) {
 return b != 0 ? gcd(b, a % b) : a;
}
void solve() {
	int N, X; cin >> N >> X;
	vector<int> x(N);
	for (int i = 0; i < N; ++i) {
		cin >> x[i];
		//現在位置との距離(絶対値)を格納した配列を作る
		x[i] = abs(X - x[i]);
	}
	int ans = x[0];
	//全ての距離を割り切れる中で最大の数(最大公約数)をユークリッド互除法で求める
	for (int i = 1; i < x.size(); ++i) {
		ans = gcd(ans, x[i]);
	}
	cout << ans << endl;
	return;
}
int main() {
	solve();
	return 0;
}