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
	ll n, x,diff=100000000;
	bool res = true;
	cin >> n >> x;
	vector<ll>city(n),vdiff(n-1);
	rep(i, n)cin >> city[i];
	if (n == 1) { cout << abs(x - city[0]); return 0; }
	rep(i, n - 1)diff = min(diff, gcd(abs(city[i] - x), abs(city[i + 1] - x)));
	cout << diff << endl;
	return 0;
}

