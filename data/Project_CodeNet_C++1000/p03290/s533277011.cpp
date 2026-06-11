#include <bits/stdc++.h>
using namespace std;
long long mypow(long long x, long long y)
{
	long long result = 1;
	while (y != 0) {
		if (y%2 != 0) {
			result *= x;
			y -= 1;
		}	
		x *= x;
		y /= 2;
	}
	return result;
}
int main(void)
{
	int d, g;
	cin >> d >> g;
	int p[d], c[d];
	for (int i = 0; i < d; i++) {
		cin >> p[i] >> c[i];
	}

	long long ans = -1;
	for (int i = 0; i < mypow(2, d); i++) {
		bool all[d];
		long long count = 0;
		long long score = 0;
		for (int j = 0; j < d; j++) {
			if (((i>>j)&1) == 1) {
				all[j] = true;
				count += p[j];
				score += (100 * (j+1) * p[j] + c[j]);
			} else {
				all[j] = false;
			}
		}
		for (int j = d-1; j >= 0; j--) {
			if (score >= g)
				break;
			if (all[j])
				continue;

			long long a = min((long long)p[j], (g-score)/((j+1)*100));
			count += a;
			score += (j+1)*100*a;
			if (a == p[j])
				score += c[j];
		}
		if (score >= g) {
			if (ans == -1)
				ans = count;
			else
				ans = min(ans, count);
		}
	}
	cout << ans << endl;
	return 0;
}