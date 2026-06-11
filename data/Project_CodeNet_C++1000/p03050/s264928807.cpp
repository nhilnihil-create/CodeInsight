#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

ll n;
ll ans = 0;

int f(ll x){
	ll m = n/x-1;
	if(m != 0) if(n/m == n%m) ans += m;
	return 0;
}

int main(){
	cin >> n;
	ll n_ya = n;//in
	for(ll i_ya = 1; i_ya * i_ya <= n_ya; i_ya++){
		if(n_ya % i_ya == 0){
			f(i_ya);
			if(i_ya != n_ya/i_ya){
				f(n_ya/i_ya);
			}
		}
	}
	cout << ans << endl;
	return 0;
}