#include <cstdio>
#include <map>
typedef long long ll;
using namespace std;

int main() {
	ll n, m; scanf("%lld%lld", &n, &m);
	multimap<ll, ll> ab_map;

	// mapはソートされる
	for (int i = 0; i < n; ++i) {
		ll a, b; scanf("%lld%lld", &a, &b);
		ab_map.insert(make_pair(a, b));
	}

	ll ans = 0;
	for (auto itr = ab_map.begin(); itr != ab_map.end(); ++itr) {
		ll price = itr->first;
		ll cnt = itr->second;

		if (cnt > m) {
			ans += price * m;
			break;
		}
		else {
			ans += price * cnt;
			m -= cnt;
		}

	}

	printf("%lld\n", ans);
	return 0;
}