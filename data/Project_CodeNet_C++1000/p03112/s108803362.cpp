
// D - Lazy Faith

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

const ll INF = 1e11;
ll s[100002];
ll t[100002];

int A, B, Q;

ll calc(ll x) {
	int l, r;
	r = lower_bound(s, s+A+2, x) - s;
	l = r - 1;
	ll s_l = s[l];
	ll s_r = s[r];

	r = lower_bound(t, t+B+2, x) - t;
	l = r - 1;
	ll t_l = t[l];
	ll t_r = t[r];

	ll result = INF;

	result = min(result, abs(x - s_l) + abs(s_l - t_l));
	result = min(result, abs(x - t_l) + abs(t_l - s_l));
	result = min(result, abs(x - s_r) + abs(s_r - t_r));
	result = min(result, abs(x - t_r) + abs(t_r - s_r));
	result = min(result, abs(x - s_l) + abs(s_l - t_r));
	result = min(result, abs(x - t_l) + abs(t_l - s_r));
	result = min(result, abs(x - s_r) + abs(s_r - t_l));
	result = min(result, abs(x - t_r) + abs(t_r - s_l));

	return result;
}

int main() {

	cin >> A >> B >> Q;

	s[0] = -INF;
	s[A+1] = INF;
	for (int i=1; i<=A; i++) {
		cin >> s[i];
	}

	t[0] = -INF;
	t[B+1] = INF;
	for (int i=1; i<=B; i++) {
		cin >> t[i];
	}

	vector<ll> ans_list;

	for (int i=0; i<Q; i++) {
		ll x;
		cin >> x;

		ans_list.push_back(calc(x));
	}

	for (ll ans : ans_list) {
		cout << ans << endl;
	}

	return 0;
}