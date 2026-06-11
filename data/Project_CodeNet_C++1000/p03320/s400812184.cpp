#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define ld long double
#define pb push_back
#define all(x) (x).begin(), (x).end()
template <typename T> using ord_set = tree <T, null_type, less <T>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int s(ll x) {
	int res = 0;
	do {
		res += x % 10;
		x /= 10;
	}	while (x);
	return res;
}

bool good(ll x, ll y) {
	return x * s(y) < y * s(x);
}

vector <ll> vec;

ll f(ll x) {
	vec.clear();
	ll cur = 1, suf = 0;
	do {
		vec.pb(x * cur + suf);
		x /= 10;
		suf = suf * 10 + 9;
		cur *= 10;
	}	while (x);
	ll mn = -1;
	for (ll i : vec) {
		if (mn == -1 || good(i, mn)) mn = i;
	}
	return mn;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
	#endif
	
	int k;
	cin >> k;
	ll n = 1;
	while (k--) {
		cout << n << '\n';
		n = f(n + 1);
	}
}
