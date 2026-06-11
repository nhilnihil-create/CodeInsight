
#include <bits/stdc++.h>

#define M_PI       3.14159265358979323846   // pi

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> t3;
typedef tuple<ll, ll, ll, ll> t4;

#define rep(a,n) for(ll a = 0;a < n;a++)

static const ll INF = 1e18;

template<typename T>
static inline void chmin(T& ref, const T  value) {
    if (ref > value) ref = value;
}

template<typename T>
static inline void chmax(T& ref, const T value) {
    if (ref < value) ref = value;
}

ll solve(ll left, ll right, function<ll(ll)> pred) {
	while (right - left > 1) {
		ll middle = left + right;
		middle /= 2;
		if (pred(middle)) {
			right = middle;
		}
		else {
			left = middle;
		}
	}
	return right;
}


int main() {
	ll k;
	cin >> k;
	vector<ll> as(k);
	rep(i, k) cin >> as[i];
	auto lower = solve(0, 1e15, [&](ll middle) {
		rep(i, k) {
			middle = middle / as[i] * as[i];
		}
		return middle >= 2;
	});
	auto upper = solve(0, 1e15, [&](ll middle) {
		rep(i, k) {
			middle = middle / as[i] * as[i];
		}
		return middle > 2;
		});
	upper--;
	if (lower > upper) {
		cout << -1 << endl;
	}
	else {
		cout << lower << " " << upper << endl;
	}
	return 0;
}
