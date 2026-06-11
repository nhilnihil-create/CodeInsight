//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define INF 0x6fffffff
#define INFL 0x6fffffffffffffffLL

int main() {
	ll		a,b,c,h,i,j,k,l,m,n,x,y;
	ll		ans = 0;
	string	s;
	cin >> n;
	for(i=1;i<=(ll)sqrt(n);i++) {
		if (n%i!=0) continue;
		m = n/i - 1;
		if (m==0) continue;
		if (n/m == n%m)	ans += m;
		//if (i<n/3) break;
	}

	cout << ans << endl;
	return 0;
}
