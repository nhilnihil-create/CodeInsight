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
	cin >> n >> s;
	//vector<ll>	aa(256);
	//for(i=0;i<n;i++) cin >> aa[i];
	//vector<ll>	dp(n+1,INFL);
	//vector<vector<ll>>	dp2(x , vector<ll>(y,INFL));
	map<char,int> mae , ato;
	for(c=1;c<n;c++) {
		mae.clear();
		ato.clear();
		for(i=0;i<n;i++) {
			if (i<c) {
				mae[s[i]] = 1;
			} else {
				ato[s[i]] = 1;
			}
		}
		a = 0;
		for(auto p:mae) {
			if (ato.count(p.first)) a++;
		}
		ans = max(ans,a);
	}
	cout << ans << endl;
	return 0;
}
