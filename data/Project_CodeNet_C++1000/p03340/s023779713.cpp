/* be name Khoda */
#include <bits/stdc++.h>
using namespace std;

const int N = 200 * 1001;
int n, a[N], res[N];
long long sum, xo, ans;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int p1 = 0, p2 = 0;
	while (p1 < n) {
		bool bad = false;
		while (p2 < n) {
			sum += a[p2];
			xo ^= a[p2];
			if (sum != xo) {
				res[p1] = max(res[p1 - 1], p2 - 1);
				sum -= (a[p1] + a[p2]);
				xo = sum;
				bad = true;
				break;
			}
			else if (sum == xo && p2 == n - 1 && !bad) {
				res[p1] = p2;
				break;
			}
			else
				p2++;
		}
		p1++;
//		cout << p2 << "  " << sum << " " << " */ \n";
	}
	for (int i = 0; i < n; i++) {
//		cout << res[i] << "  --- ";
		ans += (res[i] - i + 1);
	}
	cout << ans << endl;
}
				