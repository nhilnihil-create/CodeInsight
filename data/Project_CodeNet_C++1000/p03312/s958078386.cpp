#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;


int main(void) {
	int n, i;
	ll a[200003] = {}, m1, m2, ans = 1e20;
	ll* p1, * p2;

	cin >> n;
	for (i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] += a[i - 1];
	}

	for (i = 2; i < n - 1; i++) {
		p1 = lower_bound(a + 1, a + i, a[i] / 2 + 1);
		p2 = lower_bound(a + i + 1, a + n + 1, (a[n] + a[i]) / 2 + 1);
		for (int t1 = 0; t1 < 2; t1++) {
			for (int t2 = 0; t2 < 2; t2++) {
				m1 = max({ *p1,a[i] - *p1,*p2 - a[i],a[n] - *p2 });
				m2 = min({ *p1,a[i] - *p1,*p2 - a[i],a[n] - *p2 });
				ans = min(ans, m1 - m2);
				p2--;
			}
			p1--;
			p2 += 2;
		}
	}

	cout << ans << endl;

	return 0;
}