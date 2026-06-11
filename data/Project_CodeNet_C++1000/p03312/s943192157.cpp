#include <iostream>
#include <cstdio>
#define N 200005
using namespace std;

typedef long long ll;
ll n, mn = 1e18, m, l, r, a[N];

ll Abs(ll p) {return p > 0 ? p : -p;}

int main()
{
	ll i;
	cin >> n;
	for (i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		a[i] += a[i - 1];
	}
	r = 3;
	for (m = 2; m < n; m++) {
		while (Abs(a[l] - a[m] + a[l]) >= Abs(a[l + 1] - a[m] + a[l + 1])) l++;
		while (Abs(a[r] - a[m] - a[n] + a[r]) >= Abs(a[r + 1] - a[m] - a[n] + a[r + 1])) r++;
		mn = min(mn, max(max(a[l], a[m] - a[l]), max(a[r] - a[m], a[n] - a[r])) - min(min(a[l], a[m] - a[l]), min(a[r] - a[m], a[n] - a[r])));
	}
    cout << mn << endl;
    return 0;
}