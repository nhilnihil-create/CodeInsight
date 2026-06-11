#include <bits/stdc++.h>

#define M_PI       3.14159265358979323846   // pi

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> VI;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> t3;
typedef tuple<ll, ll, ll, ll> t4;
typedef tuple<ll, ll, ll, ll, ll> t5;

#define rep(a,n) for(ll a = 0;a < n;a++)
#define repi(a,b,n) for(ll a = b;a < n;a++)

using namespace std;

static const ll INF = 1e15;

int main() {
	ll n;
	cin >> n;
	vector<ll> as(n), bs(n), cs(n);
	rep(i, n) cin >> as[i];
	rep(i, n) cin >> bs[i];
	rep(i, n) cin >> cs[i];
	sort(as.begin(), as.end());
	sort(bs.begin(), bs.end());
	sort(cs.begin(), cs.end());

	vector<ll> pb(n);
	rep(i, n) {
		auto b = bs[i];
		auto it = upper_bound(cs.begin(), cs.end(), b);
		pb[i] = cs.end() - it;
	}
	vector<ll> pbsum(n+1, 0);
	rep(i, n) {
		pbsum[n - 1 - i] = pbsum[n - i] + pb[n - i - 1];
	}
	ll sum = 0;
	rep(i, n) {
		auto a = as[i];
		auto it = upper_bound(bs.begin(), bs.end(), a);
		int index = it - bs.begin();
		sum += pbsum[index];
	}
	cout << sum << endl;
	return 0;
}
