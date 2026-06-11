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
	int H, W; cin >> H >> W;
	vector<vector<int>> a(H, vector<int>(W, 0));
	int cnt = 0;
	vector<pair<int, int>> ans;
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			cin >> a[i][j];
		}
	}
	//奇数枚のマスは下のマスはコインを一枚配布し、偶数となる
	//下端に都合の悪いコインを押し付ける
	for (int i = 0; i < H - 1; ++i) {
		for (int j = 0; j < W; ++j) {
			if (a[i][j] % 2 == 1) {
				cnt++;
				a[i][j]--;
				a[i + 1][j]++;
				ans.push_back({i + 1, j + 1});
				ans.push_back({i + 2, j + 1});
			}
		}
	}
	//奇数枚のマスは右のマスにコインを一枚配布し、偶数となる
	//一番右(全体で右下)のマスに都合の悪いコインを押し付ける
	//一番右(全体で右下)のマスの偶奇は全体枚数の偶奇に従うので、一番右下のマス以外をこれで全て偶数にすることが出来る
	for (int i = 0; i < (W - 1); ++i) {
		if (a[H - 1][i] % 2 == 1) {
			cnt++;
			a[H - 1][i]--;
			a[H - 1][i + 1]++;
			ans.push_back({H, i + 1});
			ans.push_back({H, i + 2});
		}
	}
	int loop = 0;
	cout << cnt << endl;
	for (auto& p : ans) {
		if (loop % 2 == 0) {
			cout << p.first << " " << p.second << " ";
		} else {
			cout << p.first << " " << p.second << endl;
		}
		loop++;
	}
	return;
}
int main() {
	solve();
	return 0;
}