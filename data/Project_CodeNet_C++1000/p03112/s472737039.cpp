#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	ll a,b,q;
	cin >> a >> b >> q;
	vector<ll> s(a+1,-1e18);
	vector<ll> t(b+1,-1e18);

	for(int i=1; i<=a; i++) cin >> s[i];
	s.push_back(1e18);
	for(int i=1; i<=b; i++) cin >> t[i];
	t.push_back(1e18);

	while(q--){
		ll x;
		cin >> x;
		
		int i = lower_bound(begin(s), end(s), x) - begin(s);
		int j = lower_bound(begin(t), end(t), x) - begin(t);
		ll res = 1e18;

		for(int ii: {i-1,i}){
			for(int jj: {j-1,j}){
				res = min(res,abs(s[ii]-x)+abs(t[jj]-s[ii]));
				res = min(res,abs(t[jj]-x)+abs(s[ii]-t[jj]));
			}
		}

		cout << res << endl;
	}
	return 0;
}