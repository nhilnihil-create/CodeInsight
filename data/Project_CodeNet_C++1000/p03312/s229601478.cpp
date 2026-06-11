#include <bits/stdc++.h>
using namespace std;

typedef long long Long;

const int N = 2e5 + 2;
const Long INF = 1e18 + 7;

int a[N];
Long L[N];
Long R[N];
Long sum1L[N];
Long sum2L[N];
Long sum1R[N];
Long sum2R[N];

Long diff(Long sum, Long a) {
	Long b = sum - a;
	return max(sum - a, sum - b);
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i ++) {
		L[i] = L[i - 1] + a[i];
	}
	for (int i = n; i >= 1; i --) {
		R[i] = R[i + 1] + a[i];
	}
	int itL = 1;
	for (int i = 2; i <= n - 2; i ++) {
		while (itL < i - 1 && (diff(L[i], L[itL]) >= diff(L[i], L[itL + 1]))) {
			itL ++;
		}
		sum1L[i] = L[itL];
		sum2L[i] = L[i] - L[itL];
	}
	int itR = n;
	for (int i = n - 1; i >= 3; i --) {
		while (itR > i + 1 && (diff(R[i], R[itR]) >= diff(R[i], R[itR - 1]))) {
			itR --;
		}
		sum1R[i] = R[itR];
		sum2R[i] = R[i] - R[itR];
	}
	Long ans = INF;
	for (int i = 2; i <= n - 2; i ++) {
		Long diff = max(abs(sum1L[i] - sum2L[i]), abs(sum1R[i + 1] - sum2R[i + 1]));
		diff = max(diff, abs(min(sum1L[i], sum2L[i]) - max(sum1R[i + 1], sum2R[i + 1])));
		diff = max(diff, abs(max(sum1L[i], sum2L[i]) - min(sum1R[i + 1], sum2R[i + 1])));
		ans = min(ans, diff);
	}
	cout << ans;

	return 0;
}
