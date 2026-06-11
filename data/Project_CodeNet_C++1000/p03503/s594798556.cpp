#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <string>
#include <iomanip>
#include <queue>
#include <algorithm>
#include <set>
#include <climits>
#include <sstream>
#include <bitset>
using namespace std;
using ll = long long int;
using dd = long double;
const ll MOD = 1e9 + 7;
const dd PI = 3.1415926535;

class UnionFind {
	std::vector<int> p;

public:
	UnionFind(int n) : p(n, -1) {}

	int root(int x) { return p[x] < 0 ? x : p[x] = root(p[x]); }

	bool same(int x, int y) { return root(x) == root(y); }

	bool unite(int x, int y) {
		x = root(x);
		y = root(y);
		if (x == y) return false;
		if (p[y] < p[x]) std::swap(x, y);
		if (p[x] == p[y]) --p[x];
		p[y] = x;
		return true;
	}
};

ll fast(ll n, ll k) {
	if (k == 0) {
		return 1;
	}
	if (k == 1) {
		return n;
	}
	if (k % 2 == 0) {
		ll tmp = fast(n, k / 2);
		return tmp * tmp % MOD;
	}
	else {
		ll tmp = fast(n, k / 2);
		tmp = tmp * tmp % MOD;
		return n * tmp % MOD;
	}
}

ll count(ll n, ll k) {
	ll cnt = 0;
	while (true)
	{
		if (n >= k) {
			break;
		}
		cnt++;
		n *= 2;
	}
	return cnt;
}

int main() {
	ll N;
	cin >> N;

	// 0..5 AM
	// 5..10 PM
	vector<vector<ll>> SHOP(10);

	for (ll i = 0; i < N; i++)
	{
		for (ll j = 0; j < 5; j++)
		{
			ll am, pm;
			cin >> am >> pm;
			if (am) {
				SHOP[j].push_back(i);
			}
			if (pm) {
				SHOP[j + 5].push_back(i);
			}
		}
	}

	vector<vector<ll>> p(N, vector<ll>(11, 0));
	for (ll i = 0; i < N; i++)
	{
		for (ll j = 0; j <= 10; j++)
		{
			cin >> p[i][j];
		}
	}


	ll ans = INT_MIN;
	for (ll i = 1; i < (1 << 10); i++)
	{
		vector<ll> kasanari(N, 0);


		for (ll j = 0; j < 10; j++)
		{
			for (auto&& d : SHOP[j])
			{
				if (bitset<10>(i)[j]) {
					kasanari[d] += 1;
				}
			}
		}

		ll cur = 0;
		for (ll j = 0; j < N; j++)
		{
			cur += p[j][kasanari[j]];
		}
		ans = max(ans, cur);
	}
	cout << ans << endl;
}