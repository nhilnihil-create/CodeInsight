#include <iostream>
#include <algorithm>
#define flush fflush(stdout)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, int> Pl;
const int mod = (int)1e9 + 7, INF = (int)1e9;
const int di[4] = { 1,0,-1,0 }, dj[4] = { 0,1,0,-1 };


int main(void) {
	int n, i, a[53], amin, amax, mini, maxi;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	amin = INF;
	amax = -INF;
	for (i = 0; i < n; i++) {
		if (amin > a[i]) {
			amin = a[i];
			mini = i;
		}
		if (amax < a[i]) {
			amax = a[i];
			maxi = i;
		}
	}

	if (amin >= 0) {
		printf("%d\n", n - 1);
		for (i = 0; i < n - 1; i++) {
			printf("%d %d\n", i + 1, i + 2);
		}
		return 0;
	}

	if (amax <= 0) {
		printf("%d\n", n - 1);
		for (i = n - 1; i > 0; i--) {
			printf("%d %d\n", i + 1, i);
		}
		return 0;
	}

	printf("%d\n", n * 2 - 1);

	if (amax >= -amin) {
		for (i = 0; i < n; i++) {
			printf("%d %d\n", maxi + 1, i + 1);
		}
		for (i = 0; i < n - 1; i++) {
			printf("%d %d\n", i + 1, i + 2);
		}
	}
	else {
		for (i = 0; i < n; i++) {
			printf("%d %d\n", mini + 1, i + 1);
		}
		for (i = n - 1; i > 0; i--) {
			printf("%d %d\n", i + 1, i);
		}
	}

	return 0;
}