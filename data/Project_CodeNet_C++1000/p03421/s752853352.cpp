#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO

#ifdef FASTIO
#define scanf abacaba
#define printf abacaba
#endif

typedef long long ll;
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

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	int n, a, b;
	cin >> n >> a >> b;
	if (n > ll(a) * b || n < a + b - 1) {
		cout << -1 << "\n";
		return 0;
	}
	vector<int> vv;
	for (int i = b; i >= 1; --i)
		vv.push_back(i);
	int cur = b + 1;
	int left = n - b - (a - 1);
	for (int i = 1; i < a; ++i) {
		int go = min(b - 1, left);
		for (int j = cur + go; j >= cur; --j)
			vv.push_back(j);
		left -= go;
		cur += go + 1;
	}
	for (int i: vv)
		cout << i << " ";
	cout << "\n";
	return 0;
}


