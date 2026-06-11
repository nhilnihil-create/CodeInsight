#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
	
	ll n;
	cin >> n;
	vector<ll> a(n);
	rep(i,n) cin >> a[i];
	
	rep(i,n){
		if(a[i] > i){
			cout << -1 << endl;
			return 0;
		}
		if(i-1>=0 && a[i] - a[i-1] >= 2){
			cout << -1 << endl;
			return 0;
		}
	}
	
	
	ll res = 0;
	rep(i,n){
		res += a[i];
		if(i-1>=0 && a[i] - a[i-1] == 1) res -= a[i-1];
	}

	cout << res << endl;
	return 0;
}
