#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// 約数列挙
vector<long long> calc_divisor(long long n) {
	vector<long long> res;
	for (long long i = 1LL; i * i <= n; ++i) {
		if (n % i == 0) {
			res.push_back(i);
			long long j = n / i;
			if (j != i) res.push_back(j);
		}
	}
	sort(res.begin(), res.end());
	return res;
}

int main() {
	
	ll n, m; cin >> n >> m;
	vector<long long> div = calc_divisor(m);
	ll cnt = div.size();
	ll index = cnt - 1;
	ll ans;
	while (cnt--) {
		if (n * div[index] <= m) {
			ans = div[index];
			break;
		}
		index--;
	}
	cout << ans << endl;
	return 0;
}