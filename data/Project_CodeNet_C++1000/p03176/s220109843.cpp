#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
const int nax = 2e5 + 10;
ll d[nax];

ll maxi(int k){
	ll s = 0;
	while(k > 0){
		s = max(d[k], s);
		k -= k & -k;
	}
	return s;
}

void add(int k, ll x){
	while(k <= n){
		d[k] = max(d[k], x);
		k += k&-k;
	}
}



int main(){
	cin >> n;
	ll h[n]; ll b[n];
	for (int i = 0; i < n; ++i) cin >> h[i];
	for (int i = 0; i < n; ++i) cin >> b[i];
	for(int i = 0; i < n; ++i){
		ll t = maxi(h[i] - 1);
		add(h[i], t + b[i]);
	}
	cout << maxi(n);
}