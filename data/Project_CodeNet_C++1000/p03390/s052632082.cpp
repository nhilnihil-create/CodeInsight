// #pragma GCC optimize("Ofast,no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
using namespace std;
#define N 1000005
#define ll long long
#define debug(a) cout<<#a<<": ";for(auto i:a)cout<<i<<" ";cout<<endl;
#define trace(a) cout<<#a<<": "<<a<<endl;
#define int ll
// int a[N];
int a,b;
bool check(int val) {
	int mid = val/2;
	int ma = 0;
	for(int i = max(mid-10,1LL);i <= min(mid+10,val);i++) {
		// 1 -> val, 2 -> val-1, i -> val-i+1
		if(i == a || val-i+1 == b) continue;
		ma = max(ma,i*(val - i + 1));
	}
	// cout << val << " " << ma << endl;
	if(ma < a*b) {
		return true;
	}
	return false;
}
signed main() {
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	int i,j,k,l,m,n,t;
	cin >> t;
	while(t--) {
		// ll a,b;
		cin >> a >> b;
		if(a > b) swap(a,b);
		if(a == 1 && b == 1) {
			cout << "0" << endl;
			continue;
		}
		l = 0;
		int r = 2e9;
		ll ans = 0;
		while(l <= r) {
			int mid = (l+r)/2;
			if(check(mid)) {
				ans = mid;
				l = mid+1;
			}
			else {
				r = mid-1;
			}
		}
		cout << ans-1 << endl;
	}
}