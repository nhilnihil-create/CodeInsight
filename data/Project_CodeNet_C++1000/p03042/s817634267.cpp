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
	y = (s[0]-'0')*10+s[1]-'0';
	m = (s[2]-'0')*10+s[3]-'0';
	if (y==0) y=13;
	if (m==0) m=13;
	if ((y>12)&&(m>12)) cout << "NA" << endl;
	else if ((y>12)&&(m<=12)) cout << "YYMM" << endl;
	else if ((y<=12)&&(m>12)) cout << "MMYY" << endl;
	else cout << "AMBIGUOUS" << endl;
	return 0;
}
