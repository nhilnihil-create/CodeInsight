#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;

ll n, p, ans=1;
int main() {
	cin >> n >> p;
	if(n==1) {return printf("%lld", p)*0;}
	for(ll i=1; pow(i,n)<=p; i++) {
		if(p % (ll)pow(i,n) == 0) ans = i;
	}
	cout << ans;
	return 0;
}