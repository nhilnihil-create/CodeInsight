//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define INF 0x6fffffff
#define INFL 0x6fffffffffffffffLL

int main() {
	ll		a,b,c,q,h,i,j,k,m,n,x,y;
	ll		ans = 0;
	string	s;
	cin >> n >> q;
	cin >> s;
	vector<ll>		aa(n+1);
	vector<ll>		l(q),r(q);
	c = 0;
	for(i=2;i<=n;i++) {
		if (s[i-2]=='A' && s[i-1]=='C') c++;
		aa[i] = c;
	}
	for(i=0;i<q;i++) cin >> l[i] >> r[i];
	for(i=0;i<q;i++) {
		ans = aa[r[i]] - aa[l[i]];
		//if (aa[l[i]-1] != aa[l[i]]) ans--;
		cout << ans << endl;
	}

	return 0;
}
