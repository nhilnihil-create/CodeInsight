//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define INF 0x6fffffff
#define INFL 0x6fffffffffffffffLL
int main() {
	ll		h,i,j,k,l,m,n,x,y,z;
	ll		ans = 0;
	string	s;
	cin >> x >> y >> z >> k;
	vector<ll>	a(x), b(y), c(z), ab(x*y), abc(k*z);

	for(i=0;i<x;i++) cin >> a[i];
	for(i=0;i<y;i++) cin >> b[i];
	for(i=0;i<z;i++) cin >> c[i];

	m = 0;
	for(i=0;i<x;i++) {
		for(j=0;j<y;j++) {
			ab[m++] = a[i]+b[j];
		}
	}
	sort(ab.begin(),ab.end());
	reverse(ab.begin(),ab.end());
	m = 0;
	for(i=0;i<min(k,x*y);i++) {
		for(j=0;j<z;j++) {
			abc[m++] = ab[i]+c[j];
		}
	}
	sort(abc.begin(),abc.end());
	reverse(abc.begin(),abc.end());
	for(i=0;i<k;i++) cout << abc[i] << endl;

}
