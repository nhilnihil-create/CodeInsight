#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()
#define V vector
typedef V<int> vi;
typedef V<vi> vvi;
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
constexpr auto INF = INT_MAX >> 1;
constexpr auto LINF = 5000000000000000;
constexpr auto MOD = 1000000007;

ll fx(ll n) {

	V<ll> one(60);
	for (ll i = 0;i < 60;i++) {
		ll p = 1LL << (i + 1);
		one[i] = (((n + 1) / p) * (p / 2) + max(((n + 1) % p) - (p / 2), 0LL)) % 2;
	}

	ll re = 0;
	for (ll i = 0;i < 60;i++)if (one[i])re += 1LL << i;

	return re;
}

int main() {

	ll a, b;
	cin >> a >> b;
	ll ans = fx(b) ^ fx(a - 1);

	cout << ans << endl;

}