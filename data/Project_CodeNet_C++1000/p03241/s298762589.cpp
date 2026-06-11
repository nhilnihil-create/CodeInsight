#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	long long n, m;
	cin >> n >> m;
	long long ans = 1;
	for (long long i = 1; i*i <= m; i++) {
		if (m%i != 0)
			continue;
		long long r = m/i;
		if ((r/n) >= 1)
			ans = max(i, ans);
		
		if ((i/n) >= 1)
			ans = max(r, ans);
	}
	if (n == 1)
		ans = m;
	cout << ans << endl;
	return 0;
}