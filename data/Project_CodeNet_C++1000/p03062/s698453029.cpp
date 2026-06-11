//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define INF 0x6fffffff
#define INFL 0x6fffffffffffffffLL

int main() {
	ll		b,c,h,i,j,k,l,m,n,x,y;
	ll		ans = 0;
	string	s;
	cin >> n;
	vector<ll>	a(n);
	bool zero=false,odd=false;
	for(i=0;i<n;i++) {
		cin >> a[i];
		if (a[i]==0) zero = true;
		if (a[i]<0) {
			odd = !odd;
			a[i] = -a[i];
		}
		ans += a[i];
	}
	if (!zero && odd) {
		ll m = a[0];
		for(i=1;i<n;i++) {
			m = min(m , a[i]);
		}
		ans -= 2*m;
	}
	cout << ans << endl;
	return 0;
}
