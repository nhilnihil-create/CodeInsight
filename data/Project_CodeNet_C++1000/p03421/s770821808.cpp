#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;

ll n, a, b;
int main() {
	ll i, j, k=0, z;
	cin >> n >> a >> b;
	if(n < a+b-1 || n > a*b) return puts("-1")*0;
	for(i=a-1; i>=0; i--) {
		z = min(b, n-i);
		for(j=0; j<z; j++) printf("%lld ", k+z-j);
		k += z;
		n -= z;
	}
	return 0;
}