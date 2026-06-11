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
	//vector<ll>	aa(n);
	m = INFL;
	for(i=0;i<5;i++) {
		cin >> a;
		m = min(m,a);
	}
	ans = (n + m - 1) / m + 4;
	//vector<ll>	dp(n+1,INFL);
	//vector<vector<ll>>	dp2(x , vector<ll>(y,INFL));

	cout << ans << endl;
	return 0;
}
