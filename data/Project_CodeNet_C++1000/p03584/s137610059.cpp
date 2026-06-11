#include <bits/stdc++.h>
using namespace std;

const int N = 100100;

int a[N], b[N];
int n, k;

int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];
	long long ans = 0;
	int res = 0;
        ++k;
	for (int x = 30; x >= 0; --x) {
		res ^= (1 << x);
		if (k & (1 << x)) {
			long long cur = 0;
			for (int i = 0; i < n; ++i) {
				if ((a[i] & res) == 0) cur += b[i];
			}
			res ^= (1 << x);
			ans = max(ans, cur);
		}
	}
	cout << ans << endl;
	
	return 0;
}