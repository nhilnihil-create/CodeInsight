#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;

ll n, a, b, s, mn=1e9;
int main() {
	cin >> n;
	while(n--) {
		scanf("%lld%lld", &a, &b);
		s += a;
		if(a>b) mn = min(mn, b);
	}
	cout << (mn<1e9 ? s-mn : 0);
	return 0;
}