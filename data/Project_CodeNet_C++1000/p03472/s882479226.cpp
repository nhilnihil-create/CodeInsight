#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> P;
#define INF 10000000000000
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for(ll i = 1; i < (ll)(n); i++)
#define repN_1(i, n) for(ll i = 0; i < (ll)(n - 1); i++)
#define repM(i, n) for(ll i = (ll)(n - 1); i >= 0; i--)
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main()
{
	cout << fixed << setprecision(18);
	ll n, h;
	cin >> n >> h;

	vector<ll> a(n), b(n);

	rep(i, n) 
		cin >> a[i] >> b[i];

	sort(a.begin(), a.end(), greater<>());
	sort(b.begin(), b.end());


	ll ans = 0;
	while (h > 0) {
		if (!b.empty() && b.back() > a[0]) {
			h -= b.back();
			b.pop_back();
			ans++;
		}
		else {
			ll t = (h + a[0] - 1) / a[0];
			ans += t;
			break;
		}
	}


	cout << ans << endl;

	return 0;
}