//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define INF 0x6fffffff
#define INFL 0x6fffffffffffffffLL

int main() {
	ll		a,b,c,d,w,h,i,j,k,l,m,n,x,y,z;
	ll		ans = 0;
	string	s;
	cin >> n >> m;
	vector<ll>	aa(m+1);
	for(i=0;i<n;i++) {
		cin >> k;
		for(j=0;j<k;j++) {
			cin >> a;
			aa[a]++;
		}
	}
	for(i=1;i<=m;i++) {
		if (aa[i]==n) ans++;
	}

	cout << ans << endl;
	return 0;
}
