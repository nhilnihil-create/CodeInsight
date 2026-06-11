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
	cin >> n >> m;
	vector<pair<ll,ll>>	a(n);
	for(i=0;i<n;i++) cin >> a[i].first >> a[i].second;
	sort(a.begin(),a.end());

	i = 0;
	while(1) {
		if (a[i].second <= m) {
			m -= a[i].second;
			ans += a[i].first * a[i].second;
		} else {
			ans += a[i].first * m;
			break;
		}
		i++;
	}
	cout << ans << endl;
	return 0;
}
