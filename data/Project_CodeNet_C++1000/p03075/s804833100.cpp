//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define INF 0x6fffffff
#define INFL 0x6fffffffffffffffLL

int main() {
	ll		b,c,h,i,j,k,l,m,n,x,y;
	ll		ans = 0;
	string	s;
	vector<int>	a(5);
	for(i=0;i<5;i++) cin >> a[i];
	cin >> k;
	if (a[4]-a[0] > k) cout << ":(" << endl;
	else cout << "Yay!" << endl;
	return 0;
}
