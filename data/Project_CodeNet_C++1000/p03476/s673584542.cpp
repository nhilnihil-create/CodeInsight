#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
const int iINF = 1001001001;
const long long llINF = 1LL << 60;
bool isPrime(ll num)
{
	if (num < 2) return false;
	else if (num == 2) return true;
	else if (num % 2 == 0) return false;

	for (ll i = 3; i*i <= num; i += 2) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}
int main()
{
	vector<ll> sim;
	for (ll i = 3; i <= 100000; i += 2) {
		if (isPrime(i) && isPrime((i + 1) / 2))	sim.push_back(i);
	}
	//rep(i, sim.size())	cout << sim[i] << endl;
	int simSize = sim.size();
	int q;
	cin >> q;
	ll l, r;
	rep(i, q) {
		cin >> l >> r;
		int ans;
		int lower = -1, upper = simSize;
		int cur = (upper + lower) / 2;
		while (1 < upper - lower) {
			if (sim[cur] <= r)	lower = cur;
			else upper = cur;
			cur = (upper + lower) / 2;
		}
		ans = lower + 1;
		lower = -1; upper = simSize;
		cur = (upper + lower) / 2;
		while (1 < upper - lower) {
			if (sim[cur] < l)	lower = cur;
			else upper = cur;
			cur = (upper + lower) / 2;
		}
		ans -= lower + 1;
		cout << ans << endl;
	}
	return 0;
}