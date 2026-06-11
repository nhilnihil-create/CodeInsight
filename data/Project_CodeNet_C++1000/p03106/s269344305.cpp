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
	cin >> a >> b >> k;
	m = min(a , b);
	for(i=m;i>0;i--) {
		if (a%i==0 && b%i==0) {
			ans++;
			if (k==ans) break;
		}
	}
	cout << i << endl;
	return 0;
}
