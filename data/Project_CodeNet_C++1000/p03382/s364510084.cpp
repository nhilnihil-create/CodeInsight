#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)

int main(void) {
	int n; cin >> n;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];

	sort(a.begin(), a.end());

	vector<pair<ll, ll>> v(n - 1);
	rep(i, n - 1) v[i] = make_pair(abs((a.back() + 1) / 2 - a[i]), a[i]);
	sort(v.begin(), v.end());

	printf("%lld %lld\n", a.back(), v.front().second);
}