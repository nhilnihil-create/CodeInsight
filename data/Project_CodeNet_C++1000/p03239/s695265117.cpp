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
	int n, T,c,t,cost=10000;
	cin >> n >> T;
	rep(i, n) {
		cin >> c >> t;
		if (T >= t)cost = min(cost, c);
	}
	if (cost == 10000)cout << "TLE" << endl;
	else cout << cost << endl;
	return 0;
}

