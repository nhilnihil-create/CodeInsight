#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
const int MAXN = 2e5 + 10;

int n;
int A[MAXN];
ll psum[MAXN];

ll calc(int i1, int i2, int i3) {
	ll sums[4] = { psum[i1], psum[i2] - psum[i1], psum[i3] - psum[i2], psum[n] - psum[i3] };
	sort(sums, sums + 4);
	return sums[3] - sums[0];
}


int main() {

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &A[i]);
	}

	for (int i = 1; i <= n; i++) {
		psum[i] = psum[i - 1] + A[i];
	}

	ll ans = calc(1, 2, 3);

	for (int i2 = 2; i2 <= n - 1; i2++) {
		// i가 i2

		int L = 1, R = i2 - 1;
		while (L < R) {
			int M = (L + R) / 2;
			if (psum[i2] - psum[M] >= psum[M]) {
				L = M + 1;
			}
			else R = M;
		}
		if (L == i2) L--;

		vector<int> i1s;
		i1s.push_back(L);
		if (L - 1 >= 1)
			i1s.push_back(L - 1);


		L = i2 + 1, R = n;
		while (L < R) {
			int M = (L + R) / 2;
			if (psum[n] - psum[M] >= psum[M]-psum[i2]) {
				L = M + 1;
			}
			else R = M;
		}
		if (L == n) L--;

		vector<int> i3s;
		i3s.push_back(L);
		if (L - 1 >= i2 + 1)
			i3s.push_back(L - 1);

		// [1, i1], [i1+1, i2], [i2+1, i3], [i3+1, n]
		for (auto i1 : i1s) {
			for (auto i3 : i3s) {
				if (i1 + 1 <= i2 && i2 + 1 <= i3 && i3 + 1 <= n) {
					ans = min(ans, calc(i1, i2, i3));
				}
			}
		}
	}

	printf("%d", ans);
	return 0;
}