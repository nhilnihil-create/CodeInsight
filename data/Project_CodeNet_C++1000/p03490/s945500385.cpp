#ifndef LOCAL
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

typedef long long ll;
typedef long long llong;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/

bitset<17000> dp;

void check(int x, vector<int> vv) {
	int sum = 0;
	for (int i: vv)
		sum += i;
	x += sum;
	for (int i = 0; i < vv.size(); ++i)
		vv[i] *= 2;
	dp.reset();
	dp[0] = 1;
	for (int i: vv)
		dp |= (dp << i);
	if (!dp[x]) {
		cout << "No\n";
		exit(0);
	}
}


string s;
int x, y;

vector<int> vv[2];

int main() {
	cin >> s >> x >> y;
	int cur = 0;
	while (cur < s.size() && s[cur] == 'F')
		--x, ++cur;
	int tp = 0;
	while (cur < s.size()) {
		++cur;
		tp ^= 1;
		int cnt = 0;
		while (cur < s.size() && s[cur] == 'F') {
			++cur;
			++cnt;
		}
		vv[tp].push_back(cnt);
	}
	x = abs(x), y = abs(y);
	check(x, vv[0]);
	check(y, vv[1]);
	cout << "Yes\n";
	return 0;
}


