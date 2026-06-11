#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(n) begin(n), end(n)
using ll = long long;
using namespace std;

const ll INF = 1001001001001001;

int main(){
	int a, b, q;
	cin >> a >> b >> q;
	vector<ll> s(a);
	rep(snip_i, a) cin >> s.at(snip_i);
	vector<ll> t(b);
	rep(snip_i, b) cin >> t.at(snip_i);
	rep(i, q){
		ll x;
		cin >> x;
		ll sr, sl, tr, tl;
		auto itsl = lower_bound(s.begin(), s.end(), x);
		if(itsl == s.end()) sr = INF;
		else sr = *itsl;
		if(itsl == s.begin()) sl = 0;
		else{
			itsl--;
			sl = *itsl;
		}
		auto ittl = lower_bound(t.begin(), t.end(), x);
		if(ittl == t.end()) tr = INF;
		else tr = *ittl;
		if(ittl == t.begin()) tl = 0;
		else{
			ittl--;
			tl = *ittl;
		}
		ll ans = INF;
		if(sr != INF && tr != INF){
			ans = max(sr, tr) - x;
		}
		if(sl != 0 && tl != 0){
			ans = min(ans, x - min(sl, tl));
		}
		if(sl != 0 && tr != INF){
			ll add, sd = fabs(sl - x), td = fabs(tr - x);
			if(sd < td) add = sd*2 + td;
			else add = sd + td*2;
			ans = min(ans, add);
		}
		if(tl != 0 && sr != INF){
			ll add, td = fabs(tl - x), sd = fabs(sr - x);
			if(sd < td) add = sd*2 + td;
			else add = sd + td*2;
			ans = min(ans, add);
		}
		cout << ans << endl;
	}
	return 0;
}