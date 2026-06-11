//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define INF 0x6fffffff
#define INFL 0x6fffffffffffffffLL

int main() {
	ll		a,b,c,d,r,h,i,j,k,l,m,n,x,y;
	ll		ans = 0;
	string	s;
	cin >> r >> d >> x;
	//vector<ll>	aa(n);
	//for(i=0;i<n;i++) cin >> aa[i];
	//vector<ll>	dp(n+1,INFL);
	//vector<vector<ll>>	dp2(x , vector<ll>(y,INFL));
	for(i=1;i<=10;i++) {
		x = r*x-d;
		cout << x << endl;
	}
	return 0;
}
