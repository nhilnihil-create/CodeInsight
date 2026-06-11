#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

inline int binary_search(vector<ll> &v, ll val){
	if(v.back() <= val)return v.size();
	int l = 0, r = (int)v.size() - 1;
	while(l < r){
		int m = (l + r)/2;
		if(val < v[m])r = m;
		else l = m + 1;
	}
	return l;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int x, y, z, k;
	cin>>x>>y>>z>>k;
	vector<ll> a(x), b(y), c(z);
	for(int i = 0; i < x; i++){
		cin>>a[i];
	}
	for(int i = 0; i < y; i++){
		cin>>b[i];
	}
	for(int i = 0; i < z; i++){
		cin>>c[i];
	}
	sort(a.rbegin(), a.rend());
	sort(b.rbegin(), b.rend());
	sort(c.rbegin(), c.rend());
	vector<ll> v;
	for(int i = 0; i < x; i++){
		for(int j = 0; j < y; j++){
			v.push_back(a[i] + b[j]);
		}
	}
	sort(v.begin(), v.end());
	ll req;
	{
		ll cnt = x*1LL*y*z - k;
		ll lo = 0, hi = a[0] + b[0] + c[0];
		while(lo < hi){
			ll mi = lo + (hi - lo)/2;
			ll tmp = 0;
			for(int i = 0; i < z; i++){
				tmp += binary_search(v, mi - c[i]);
			}
			if(tmp < cnt)lo = mi + 1;
			else hi = mi;
		}
		req = lo;
	}
	vector<ll> vec;
	for(int i = 0; i < x; i++){
		if(a[i] + b[0] + c[0] <= req)break;
		for(int j = 0; j < y; j++){
			if(a[i] + b[j] + c[0] <= req)break;
			for(int kk = 0; kk < z; kk++){
				if(a[i] + b[j] + c[kk] <= req)break;
				vec.push_back(a[i] + b[j] + c[kk]);
			}
		}
	}
	sort(vec.rbegin(), vec.rend());
	while(vec.size() < k){
		vec.push_back(req);
	}
	for(auto x : vec){
		cout<<x<<'\n';
	}


	return 0;
}