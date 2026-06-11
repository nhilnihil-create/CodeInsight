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
	cin >> a >> b;

	if (a%2==1) {
		x = a;
		i = a+1;
	} else {
		x = 0;
		i = a;
	}
	if (b%2==1) {
		y = 0;
		j = b;
	} else {
		y = b;
		j = b - 1;
	}

	ans = x ^ y;

	if (i<j) {
		if ( ((j-i+1)/2)%2 == 1 ) {
			ans = ans^1;
		}
	}
	cout << ans << endl;
	return 0;
}
