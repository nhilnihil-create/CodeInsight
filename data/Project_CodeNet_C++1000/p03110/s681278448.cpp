//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define INF 0x6fffffff
#define INFL 0x6fffffffffffffffLL

int main() {
	ll		a,b,c,h,i,j,k,l,m,n,x,y;
	double	ans = 0;
	string	ss,s;
	cin >> n;
	for(i=0;i<n;i++) {
		cin >> ss >> s;
		if (s[0]=='B') {
			ans += stof(ss)*380000.0;
		} else {
			ans += stoi(ss);
		}
	}
	cout << ans << endl;
	return 0;
}
