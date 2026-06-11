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

int n;
ll a[120000];

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a, a + n);
	ll bst = a[0];
	for (int i = 0; i < n - 1; ++i) {
		if (abs(2 * a[i] - a[n - 1]) < abs(2 * bst - a[n - 1]))
			bst = a[i];
	}
	cout << a[n - 1] << " " << bst << "\n";
	return 0;
}


