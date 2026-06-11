#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

ll q, a, b, c, d, g, mn;
int main() {
	cin >> q;
	while(q--) {
		cin >> a >> b >> c >> d;
		g = __gcd(b, d);
		mn = a - (a-c-1) / g * g;
		puts(a<b || d<b || mn<b ? "No" : "Yes");
	}
	return 0;
}