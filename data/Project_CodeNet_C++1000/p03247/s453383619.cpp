#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

typedef long long ll;
ll n, mx, k, x[1005], y[1005];
vector<ll> b;
ll ab(ll p) {return p > 0 ? p : -p;}
ll f(ll p, ll q) {
	return ab(p) + ab(q);
}
int main()
{
	ll i, j;
	cin >> n;
	for (i = 0; i < n; i++) {
		scanf ("%lld %lld", &x[i], &y[i]);
		if (f(x[i], y[i]) % 2 != f(x[0], y[0]) % 2) {
			cout << -1;
			return 0;
		}
		mx = max(mx, f(x[i], y[i]));
	}
	if (mx % 2 == 0) b.push_back(1);
	for (k = 1; k < mx; k *= 2) b.push_back(k);
	b.push_back(k);
	cout << b.size() << endl;
	for (i = b.size() - 1; i >= 0; i--) printf("%lld ", b[i]);
	puts("");
	for (j = 0; j < n; j++) {
		for (i = b.size() - 1; i >= 0; i--) {
			if (ab(x[j]) >= ab(y[j])) {
				if (x[j] <= 0) {x[j] += b[i]; printf("L");}
				else {x[j] -= b[i]; printf("R");}
			} else {
				if (y[j] <= 0) {y[j] += b[i]; printf("D");}
				else {y[j] -= b[i]; printf("U");}
			}
		}
		puts("");
	}
//	cout << k;
    return 0;
}
