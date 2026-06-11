#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define maxs(a, b) a = max(a, b)
#define mins(a, b) a = min(a, b)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const ll linf = (1ll << 61);
const int inf = 1001001001;
const int mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	cin >> n;
	vector<ll> rec;
	for (ll i = 1; i * i <= n; ++i) {
		if (n % i == 0) {
			rec.push_back(i);
			if (i * i != n) rec.push_back(n / i);
		}
	}
	ll ans = 0;
	for (ll c : rec) {
		if (c - 1LL <= 1) continue;
		ll tmp1 = n / (c - 1LL);
		ll tmp2 = n % (c - 1LL);
		if (tmp1 == tmp2) ans += c - 1;
	}
	printf("%lld\n", ans);
	return 0;
}
