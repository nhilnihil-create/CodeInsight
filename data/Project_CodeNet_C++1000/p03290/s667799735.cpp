#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int d, g; cin >> d >> g;
	int p[11], c[11]; for (int i = 0; i < d; i++)cin >> p[i] >> c[i];

	int ans = 1e10;
	for (int b = 0; b < (1 << d); b++) {
		int s0 = 0, cnt = 0, rest = -1;
		for (int i = 0; i < d; i++) {
			if (b >> i & 1) {
				s0 += 100 * (i + 1) * p[i] + c[i];
				cnt += p[i];
			}
			else rest = i;
		}
		if (s0 < g) {
			int s1 = 100 * (rest + 1);
			int need = (g - s0 + s1 - 1) / s1;
			if (need >= p[rest])continue;
			cnt += need;
		}
		ans = min(ans, cnt);
	}
	cout << ans << endl;

	return 0;
}