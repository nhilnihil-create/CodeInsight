#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll base = 1, ans;

double S(ll x) {
	int res = 0; ll y = x;
	while (x) {
		res += x % 10;
		x /= 10;
	}
	return y / (res * 1.0);
}

int main() {
	scanf("%d", &n);
	while (n--) {
		while (1) {
			if (S(ans + base) > S(ans + base * 10))
				base *= 10;
			else break;
		}
		ans += base;
		printf("%lld\n", ans);
	}
	return 0;
}