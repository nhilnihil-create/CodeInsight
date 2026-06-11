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
	int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
	//(x1, y1)からへ移動する際の(x2, y2)へのベクトルを求める
	int dx = x2 - x1;
	int dy = y2 - y1;
	int x = x2;
	int y = y2;
	for (int i = 0; i < 2; ++i) {
		//90°の回転行列を2回用いると
		//x3, y3 = x2 - dy, y2 + dx 
		//X4, y4 = x3 - dx, y3 - dy 
		swap(dx, dy);
		dx = -dx;
		x += dx;
		y += dy;
		cout << x << " " << y << endl;
	}
	return;
}
int main() {
	solve();
	return 0;
}