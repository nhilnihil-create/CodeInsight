#include <iostream>
#include <algorithm>
#define flush fflush(stdout)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int mod = (int)1e9 + 7, INF = (int)1e9;


int main(void) {
	int n, i, j, l[70] = {}, t, kd[70] = {};
	bool cf;
	ll k, a[100003], mmax, ans;

	scanf("%d%lld", &n, &k);
	for (i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
	}

	mmax = k;
	for (i = 0; i < n; i++) {
		mmax = max(mmax, a[i]);
	}

	t = 0;
	while (mmax > 0) {
		mmax /= 2;
		t++;
	}

	for (i = 0; i < t; i++) {
		kd[i] = k % 2;
		k /= 2;
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < t; j++) {
			l[j] += a[i] % 2;
			a[i] /= 2;
		}
	}

	ans = 0;
	cf = false;
	for (i = t - 1; i >= 0; i--) {
		ans *= 2;
		if (cf) {
			ans += max(l[i], n - l[i]);
		}
		else {
			if (l[i] >= n - l[i]) {
				ans += l[i];
				if (kd[i] == 1) cf = true;
			}
			else {
				if (kd[i] == 0) ans += l[i];
				else ans += n - l[i];
			}
		}
	}

	printf("%lld\n", ans);

	return 0;
}