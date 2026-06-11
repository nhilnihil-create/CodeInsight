#include <bits/stdc++.h>
using namespace std;

int main() {

	long long a, b, c, k;
	scanf("%lld %lld %lld %lld", &a, &b, &c, &k);
	if(k % 2 == 0) {
		long long d = a - b;
		if(d >= 1e18) {
			printf("%s\n", "Unfair");
		}else {
			printf("%lld\n", d);
		}
	}else {
		long long d = b - a;
		if(d >= 1e18) {
			printf("%s\n", "Unfair");
        }else {
			printf("%lld\n", d);
		}
	}
}