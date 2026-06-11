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
	cin >> a >> b;
	if (b%a==0) ans = a + b;
	else ans = b - a;
	cout << ans << endl;
	return 0;
}
