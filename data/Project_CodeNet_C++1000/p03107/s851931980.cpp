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
	x = y = 0;
	for(i=0;i<s.size();i++) {
		if (s[i]=='0') x++;
		else y++;
	}
	ans = min(x , y) * 2;
	cout << ans << endl;
	return 0;
}
