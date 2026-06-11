#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;

int main() {
	int n, y;
	int money = 0;
	cin >> n >> y;
	rep(i, n + 1)rep(j, n - i + 1) {
		money = 10000 * i + 5000 * j + 1000 * (n - (i + j));
		if (y == money) {
			cout << i << " " << j << " " << n - (i + j) << endl;
			return 0;
		}
	}
	cout << -1 << " " << -1 << " " << -1 << endl;
	return 0;
}
