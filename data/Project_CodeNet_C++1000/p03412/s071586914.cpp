#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, ans;
vector<ll> a, b;

int main(){
//	cin.tie(0);
//	ios::sync_with_stdio(false);
	cin >> n;
	a.resize(n);
	b.resize(n);
	for(int i=0; i<n; ++i) cin >> a[i];
	for(int i=0; i<n; ++i) cin >> b[i];
	for(int i=0; i<29; ++i){
		ll t = 1 << i;
		vector<ll> c(b);
		for(int j=0; j<n; ++j) c[j] %= 2*t;
		sort(c.begin(), c.end());
//		cout << "t " << t << "\n";
//		for(int j=0; j<n; ++j) cout << c[j] << (j==n-1?"\n":" ");
		bool f = false;
		for(int j=0; j<n; ++j)
			f ^= (lower_bound(c.begin(), c.end(), 2*t-a[j]%(2*t)) - lower_bound(c.begin(), c.end(), t-a[j]%(2*t)) + lower_bound(c.begin(), c.end(), 4*t-a[j]%(2*t)) - lower_bound(c.begin(), c.end(), 3*t-a[j]%(2*t))) % 2;
		if(f) ans += t;
//		cout << "ans " << ans << "\n";
	}
	cout << ans << "\n";
}