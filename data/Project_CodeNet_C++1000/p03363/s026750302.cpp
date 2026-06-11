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
	int n;
	ll a;
	cin >> n;
	vector<ll>arr(n + 1, 0);
	rep(i, n) {
		cin >> a;
		arr[i + 1] = arr[i] + a;
	}
	map<ll, ll>m;
	for (auto s : arr)m[s]++;
	ll ans = 0;
	for (auto mp : m) {
		if (mp.second >= 2) ans += (mp.second) * (mp.second - 1) / 2;
	}
	cout << ans << endl;
	return 0;
}

