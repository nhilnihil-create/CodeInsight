//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define INF 0x6fffffff
#define INFL 0x6fffffffffffffffLL

int main() {
	ll		a,b,c,h,i,j,k,l,m,n,p,x,y;
	ll		ans = 0;
	string	s;
	cin >> n;

	map<string , map<int , int>> pp;

	for(i=1;i<=n;i++) {
		cin >> s >> p;
		pp[s][-1*p] = i;
	}
	for(auto d:pp) {
		map<int , int> qq = d.second;
		for(auto dd:qq) cout << dd.second << endl;
	}
	return 0;
}
