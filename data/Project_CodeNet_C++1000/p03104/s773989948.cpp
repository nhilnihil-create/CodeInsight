#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define INF 1999999999
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define MODA 1000000007 

int main() {
	ll ans = 0;
	ll tmp;
	ll a[2];
	cin >> a[0] >> a[1];
	a[1]++;
	ll x[2];
	REP(i,40){
		REP(j, 2){
			ll sh = a[j] / ((ll)1 << (i+1));
			ll mo = a[j] % ((ll)1 << (i+1));
			x[j] = sh * ((ll)1 << (i));
			x[j] %= 2;
			tmp = max((ll)0, mo - ((ll)1 << (i)));
			x[j] += tmp;
			x[j] %= 2;
			//cout << a[j] << " " << x[j] << " " << sh << " " << mo << endl;
		}
		ans += (x[0] ^ x[1]) * ((ll)1 << (i)); 
	}
	
	cout << ans << endl;
}
