#include <bits/stdc++.h>

#define For(i, j, k) for (int i = j; i <= k; ++ i)

using namespace std;

const int N = 2e3 + 10;
int a[N], t[N], n, k, q, b[N];

int main() {

	scanf("%d%d%d", &n, &k, &q);
	For(i, 1, n) scanf("%d", a + i); a[++ n] = -1;

	int ans = INT_MAX;
	For(tt, 1, n) {
		int nw = a[tt], c = 0, lstps = 1;

		For(i, 1, n) if (a[i] < nw) {
			if (i - lstps < k) { lstps = i + 1; continue; }
			int cnt = 0;
			For(j, lstps, i - 1) b[++ cnt] = a[j];
			nth_element(b + 1, b + cnt - k + 1, b + cnt + 1);
			For(j, 1, cnt - k + 1) t[++ c] = b[j];
			lstps = i + 1;
		}
	
		if (c < q) continue;
		nth_element(t + 1, t + q, t + c + 1);
		ans = min(ans, t[q] - nw);
	}

	cout << ans << endl;
	return 0;
}
