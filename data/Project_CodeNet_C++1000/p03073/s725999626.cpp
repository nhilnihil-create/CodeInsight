//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define INF 0x6fffffff
#define INFL 0x6fffffffffffffffLL

int main() {
	ll		a=0,b=0,c,h,i,j,k,l,m,n;
	ll		ans = 0;
	string	s;
	cin >> s;
	char x,y;
	x = '0'; y = '1';
	for(i=0;i<s.size();i++) {
		if (s[i]!=x) a++;
		if (s[i]!=y) b++;
		swap(x , y);
	}
	ans = min(a , b);
	cout << ans << endl;
	return 0;
}
