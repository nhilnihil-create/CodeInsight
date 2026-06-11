#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

int main(void){
	ll n; cin >> n; P a[n]; ll s[n]; fill(s, s+n, 1);
	for(int i=0; i<n; i++) {cin >> a[i].first; a[i].second=i+1;}
	sort(a, a+n, greater<P>()); vector<P> v;
	bool ok = true; ll ss[n]; fill(ss, ss+n, 0);

	for(int i=0; i<n-1 && ok; i++) {
		ll p = a[i].first - n + 2 * s[i];
		if (n - 2 * s[i] <= 0) ok = false;
		ll x = lower_bound(a+i+1, a+n, make_pair(p, 0), greater<P>()) - a-1 ;
		//if (x == n) ok = false;
		if (a[x].first != p) ok = false;
		s[x] += s[i]; ss[x] += ss[i] + s[i];
		ll v1 = min(a[x].second, a[i].second);
		ll v2 = max(a[x].second, a[i].second);
		v.push_back(make_pair(v1, v2));
		//cout << i << " " << x << " " << p << " " << s[x] << " " << ok << " " << a[x].first << endl;
	}
	if (ss[n-1] != a[n-1].first) ok = false;
	if (ok == false) {cout << -1 << endl; return 0;}
	sort(v.begin(), v.end());
	for(P y:v){
		cout << y.first << " " << y.second << endl;
	}
}