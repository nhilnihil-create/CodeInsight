#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(n) begin(n), end(n)
using ll = long long;
using namespace std;

int func(ll n, vector<int> &a, int level, int k){
	if(level == k){
		if(n > 2) return 1;
		else if(n == 2) return 0;
		else return -1;
	}else{
		n /= (ll)a.at(level);
		n *= (ll)a.at(level);
		return func(n, a, level+1, k);
	}
}

ll b_serch(ll l, ll r, vector<int> &a, int k){
	while(r - l > 1){
		ll mid = (l+r)/2;
		if(func(mid, a, 0, k) >= 0){
			r = mid;
		}else{
			l = mid;
		}
	}
	return r;
}

ll b_serch2(ll l, ll r, vector<int> &a, int k){
	while(r - l > 1){
		ll mid = (l+r)/2;
		if(func(mid, a, 0, k) <= 0){
			l = mid;
		}else{
			r = mid;
		}
	}
	return l;
}

int main(){
	int k;
	cin >> k;
	vector<int> a(k);
	int mx = 0;
	rep(snip_i, k){
		cin >> a.at(snip_i);
		mx = max(mx, a.at(snip_i));
	}
	ll n_mn, n_mx;
	n_mn = b_serch(1, (ll)mx*k+3, a, k);
	n_mx = b_serch2(1, (ll)mx*k+3, a, k);
	if(n_mn > n_mx){
		cout << -1 << endl;
	}else{
		cout << n_mn << " " << n_mx << endl;
	}
	
	return 0;
}