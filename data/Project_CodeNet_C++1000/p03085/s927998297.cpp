//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define INF 0x6fffffff
#define INFL 0x6fffffffffffffffLL

int main() {
	ll		a,c,h,i,j,k,l,m,n,x,y;
	char		ans;
	char	b;
	cin >> b;

	if (b=='A') ans = 'T';
	if (b=='C') ans = 'G';
	if (b=='G') ans = 'C';
	if (b=='T') ans = 'A';
	cout << ans << endl;
	return 0;
}
