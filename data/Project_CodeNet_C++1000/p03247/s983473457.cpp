#include <iostream>
#include <cstdio>
#include <vector>
#define N 1005
using namespace std;

typedef long long ll;
ll n, mx, x[N], y[N];
vector<ll> a;

ll Abs(ll p) {return p > 0 ? p : -p;}

int main()
{
	ll i, j, t;
	cin >> n;
	for (i = 0; i < n; i++) {
		scanf("%lld %lld", &x[i], &y[i]);
		t = Abs(x[i]) + Abs(y[i]);
		if (i > 0 && t % 2 != mx % 2) {cout << "-1"; return 0;}
		mx = max(mx, t);
	}
	for (i = 1; i < mx; i *= 2);
	for (; i > 0; i /= 2) a.push_back(i);
	if (mx % 2 == 0) a.push_back(1);
	cout << a.size() << endl;
	for (i = 0; i < a.size(); i++) printf("%lld ", a[i]);
	puts("");
	for (i = 0; i < n; i++) {
		for (j = 0; j < a.size(); j++) {
			if (Abs(x[i]) > Abs(y[i])) {
				if (x[i] < 0) {
					printf("L");
					x[i] += a[j];
				} else {
					printf("R");
					x[i] -= a[j];
				}
			} else {
				if (y[i] < 0) {
					printf("D");
					y[i] += a[j];
				} else {
					printf("U");
					y[i] -= a[j];
				}
			}
		}
		puts("");
	}
    return 0;
}