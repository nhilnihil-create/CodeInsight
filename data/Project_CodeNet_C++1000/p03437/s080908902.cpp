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
	ll x, y;
	cin >> x >> y;
	if (x == y) {
		cout << -1 << endl;
		return 0;
	}
	REP(i, 100000) {
		if ((x * i) % y != 0) {
			cout << x*i << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}

