#include <bits/stdc++.h>
#define LL long long
#define PII pair<int, int>
#define f first
#define s second 
using namespace std;
const LL INF = (LL) 1e9 + 5;
const LL MOD = (LL) 1e9 + 7;
//const int MAXN = 200005;

LL x, y, p;

LL want(LL k) {
	return p % k == 0 ? p / k - 1 : p / k;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> x >> y;
		p = x * y;
		if (x > y) swap(x, y);
		if (p == 1) {
			cout << "0\n";
			continue;
		}
		
		LL l = x, r = y + 1, last = x;
		while (l <= r) {
			LL m = (l + r) / 2;
			if (m * (m - 1) <= p && want(m) > 0) {
				last = m;
				l = m + 1;
			}
			else {
				r = m - 1;
			}
		}
		
		LL ans = last - 1, take = 2e18;
		if (last > x) {
			take = want(last);
		}
		else if (x != 1) {
			take = want(x - 1);
		}
		
		LL other = want(last + 1);
		if (other == take) other--;
		ans += max(other, 0LL);
		cout << ans << '\n';
	}

	return 0;
}