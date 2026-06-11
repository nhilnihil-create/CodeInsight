#include <iostream>
#include <cstdio>
#include <algorithm>
#define N 200005
using namespace std;

typedef long long ll;
ll n, ans, a[N], s[N], b[4];
ll f(ll p, ll q){
	return s[q] - s[p - 1];
}

ll ab(ll p) {return p > 0 ? p : -p;}
int main()
{
	ll i, j, k;
	cin >> n;
	for (i = 1; i <= n; i++) {
		scanf ("%lld", &a[i]);
		s[i] = s[i - 1] + a[i];
	}
	j =1;
	k = 3;
    for (i = 2; i <= n - 2; i++) {
		for (; j < i - 1; j++) {
//			if (max(f(1, j), f(j + 1, i)) < max(f(1, j + 1), f(j + 2, i))) break;
			if (ab(f(1, j) - f(j + 1, i)) < ab(f(1, j + 1) - f(j + 2, i))) break;
		}
		for (; k < n - 1; k++) {
//			if (max(f(1, j), f(j + 1, i)) < max(f(1, j + 1), f(j + 2, i))) break;
			if (ab(f(i + 1, k) - f(k + 1, n)) < ab(f(i + 1, k + 1) - f(k + 2, n))) break;
		}
		b[0] = f(1, j);
		b[1] = f(j + 1, i);
		b[2] = f(i + 1, k);
		b[3] = f(k + 1, n);
		sort(b, b + 4);
		if (i == 2 || b[3] - b[0] < ans) ans = b[3] - b[0];
    }
    cout << ans;
    return 0;
}
