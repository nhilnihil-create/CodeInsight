#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
typedef long long ll;

int main(){
	ll n,k;
	cin >> n >> k;
	vector<ll> a(n+1,0);
	REP(i,n){
		cin >> a[i];
	}
	rep(i,n){
		a[i+1] += a[i];
	}
	
	vector<ll> sum;
	for (int i = 1; i <= n; ++i) {
		for (int j = i; j <= n; ++j) {
			sum.push_back(a[j]-a[i-1]);
		}
	}
	
	ll ans = 0;
	
	for (int bit = 40; bit >= 0; --bit) {
		ll temp  = 1;
		rep(j,bit) temp*= 2;
		int count = 0;
		rep(j, n*(n+1)/2){
			if(((ans + temp) & sum[j]) == ans + temp) count++;
		}
		if(count >= k) ans += temp;
	}
	
	cout << ans << endl;
	
    return 0;
}

