//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define INF 0x6fffffff
#define INFL 0x6fffffffffffffffLL

int main() {
	ll		a,b,c,d,h,i,j,k,l,m,n,x,y;
	ll		ans = 0;
	string	s;
	cin >> s;
	//vector<ll>	aa(n);
	for(i=0;i<10;i++) s[i] -= '0';
	d = s[0]*10000000+s[1]*1000000+s[2]*100000+s[3]*10000;
	d += s[5]*1000+s[6]*100;
	d += s[8]*10+s[9];
	//cout << d << endl;
	if (d<=20190430) s = "Heisei";
	else s = "TBD";
	cout << s << endl;
	return 0;
}
