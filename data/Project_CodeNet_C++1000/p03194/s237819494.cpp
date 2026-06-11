#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
 
ll n, p, ans=1;
int main() {
	ll i, j, t;
	cin >> n >> p;
	if(n==1) {return printf("%lld", p)*0;}
	for(i=2; ; i++) {
		t = 1;
		for(j=0; j<n; j++) {
			t *= i;
			if(t<0 || t>p) {cout << ans; return 0;}
		}
		if(p%t==0) ans = i;
	}
	return 0;
}