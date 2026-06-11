//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define INF 0x6fffffff
#define INFL 0x6fffffffffffffffLL

int main() {
	ll		a,b,h,i,t,j,k,l,m,n,x,y;
	ll		ans = 0;
	string	s;
	cin >> n;

	
	vector<ll>	v(n),c(n);
	for(i=0;i<n;i++) cin >> v[i];
	for(i=0;i<n;i++) cin >> c[i];
	for(i=0;i<(1<<n);i++) {
		x = y = 0;
		for(j=0;j<=n;j++) {
			if ((i & (1<<j))!=0) {
				x += v[j];
				y += c[j];
			}
			ans = max( ans , x-y );
		}
	}
	//vector<ll>	dp(n+1,INFL);
	//vector<vector<ll>>	dp2(x , vector<ll>(y,INFL));

	cout << ans << endl;
	return 0;
}
