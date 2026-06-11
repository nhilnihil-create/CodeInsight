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
	cin >> s;
	a = 0;
	for(i=0;i<s.size();i++) {
		if (s[i]=='A'||s[i]=='C'||s[i]=='G'||s[i]=='T') {
			a++;
		} else {
			ans = max(ans , a);
			a = 0;
		}
	}
	ans = max(ans , a);
	cout << ans << endl;
	return 0;
}
