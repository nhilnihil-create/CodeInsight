#include <cstdio>
#include <algorithm>
#define N 111111
using namespace std;
int ar[N];
int main(void)
{
	int n;
	scanf("%d", &n);
	int i, j, k;
	for (i = 0; i < n; ++i) scanf("%d", ar + i);
	sort(ar, ar + n);
	printf("%d ", ar[n - 1]);
	k = (ar[n - 1] + 1) / 2;
	j = lower_bound(ar, ar + n, k) - ar;
	int l = j - 1, r = (j == n - 1 ? j : j + 1);
	int min_v = abs(k - ar[j]), ans = ar[j];
	if (abs(k - ar[l]) <= min_v) {
		min_v = k - ar[l];
		ans = ar[l];
	}
	if (abs(k - ar[r]) < min_v) ans = ar[r];
	printf("%d", ans);
}
