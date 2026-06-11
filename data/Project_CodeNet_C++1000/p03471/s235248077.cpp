#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define ll long long

int main() {
	int n, y;
	scanf("%d %d", &n, &y);
	for (ll i = 0; i <= n; i++) {
		for (ll j = 0; j <= n; j++) {
			ll k = (y - i * 10000 - j * 5000) / 1000;
			if (k + i + j == n && k >= 0) {
				return printf("%lld %lld %lld\n", i, j, k), 0;
			}
		}
	}
	printf("-1 -1 -1\n");
}
