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
	int L; cin >> L;
	int N = 0;
	vector<vector<int>> ans;
	while (1 << N <= L) N++;

	//2進数の辺を作る
	for (int i = 1; i < N; ++i) {
		ans.push_back({i, i + 1, 1 << (i - 1)});
		ans.push_back({i, i + 1, 0});
	}	

	//今現在つないでいる辺の最大長、これがL-1になるまでショートカットをつなぐ
	int now = (1 << (N - 1)) - 1;

	for (int i = N - 1; i >= 1; --i) {
		if (now == L - 1) break;
		//頂点iからのショートカットで増える最大長
		int gain = 1 << (i - 1);
		if (now + gain <= (L - 1)) {
			ans.push_back({i, N, now + 1});
			now += gain;
		}
	}
	int M = ans.size();
	cout << N << " " << M << endl;
	for (auto v : ans) {
		cout << v[0] << " " << v[1] << " " << v[2] << endl;
	}
	return;
}
int main() {
	solve();
	return 0;
}