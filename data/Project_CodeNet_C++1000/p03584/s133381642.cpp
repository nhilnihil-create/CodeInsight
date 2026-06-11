#include <bits/stdc++.h> 

using namespace std;
using ll = long long;

ll func(ll x, vector<ll>& a, vector<ll>& b) {
	ll ret = 0;
	for (int i = 0; i < a.size(); ++i) {
		if ((x | a[i]) <= x) { ret += b[i]; }
	}
	return ret;
}

int main() {
	int N;
	ll K;
	cin >> N >> K;
	vector<ll> a(N);
	vector<ll> b(N);
	for (int i = 0; i < N; ++i) {
		cin >> a[i] >> b[i];
	}

	ll sum = 0;
	ll res = func(K, a, b);
	for (int i = 30; i >= 0; --i) {
		if (((K>>i) & 1) == 0) { continue; }

		ll add = 1LL<<i;
		res = max(res, func(sum + add - 1, a, b));
		sum += add;
	}
	cout << res << endl;

	return 0;
}
