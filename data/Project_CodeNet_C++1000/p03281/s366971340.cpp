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
vector<pair<int64, int64>> prime_factorize(int64 N) {
	vector<pair<int64, int64>> res;
	for (int64 a = 2; a * a <= N; ++a) {
		if (N % a != 0) continue;
		int64 ex = 0;
		while(N % a == 0) {
			++ex;
			N /= a;
		}
		res.push_back({a, ex});
	}
	if (N != 1) res.push_back({N, 1});
	return res;
}
void solve() {
	int N; cin >> N;
	int ans = 0;
	for (int i = 1; i <= N; i+=2) {
		vector<pair<int64, int64>> ret_pair = prime_factorize(i);
		int64 tmp = 1;
		for (auto p: ret_pair) {
			tmp *= p.second + 1;
		}
		if (tmp == 8) ans++;
	}
	cout << ans << endl;
	return;
}
int main() {
	solve();
	return 0;
}