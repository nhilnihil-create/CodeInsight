#include <bits/stdc++.h>

#define M_PI       3.14159265358979323846   // pi

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> t3;

#define rep(a,n) for(ll a = 0;a < n;a++)
#define repi(a,b,n) for(ll a = b;a < n;a++)


int main(void)
{
	ll n,c;
	cin >> n >> c;
	vector<P> vs(n);
	rep(i, n) {
		cin >> vs[i].first >> vs[i].second;
	}
	vector<ll> cs1(n+1, 0);
	vector<ll> mcs1(n + 1, 0);
	rep(i, n) {
		cs1[i + 1] = cs1[i] + vs[i].second;
		mcs1[i + 1] = max(mcs1[i], cs1[i + 1] - vs[i].first);
	}
	vector<ll> cs2(n + 1, 0);
	vector<ll> mcs2(n + 1, 0);
	rep(i, n) {
		cs2[i + 1] = cs2[i] + vs[n-1-i].second;
		mcs2[i + 1] = max(mcs2[i], cs2[i + 1] - (c - vs[n-1-i].first));
	}
	ll m = max(0LL, max(mcs1[n], mcs2[n]));
	rep(i, n) {
		auto m1 = mcs1[i + 1] + mcs2[n - 1 - i] - vs[i].first;
		auto m3 = mcs2[i + 1] + mcs1[n - 1 - i] - (c - vs[n - 1 - i].first);
		m = max(m, m1);
		m = max(m, m3);
	}
	cout << m << endl;
	return 0;
}
