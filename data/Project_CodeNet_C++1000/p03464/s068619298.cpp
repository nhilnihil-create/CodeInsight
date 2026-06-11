#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(n) begin(n), end(n)
using ll = long long;
using namespace std;

int main(){
	int k;
	cin >> k;
	vector<int> a(k);
	rep(snip_i, k) cin >> a.at(snip_i);
	ll l, r;
	l = r = 2;
	rrep(i, k){
		ll x, y, n_a = a.at(i);
		if(l % n_a != 0 && r < l + (n_a - l % n_a)){
			// cerr << l % n_a << " " << r % n_a << endl;
			cout << -1 << endl;
			return 0;
		}
		x = (l+n_a-1)/n_a*n_a;
		y = r/n_a*n_a;
		l = x;
		r = y + n_a - 1;
	}
	cout << l << " " << r << endl;
	return 0;
}