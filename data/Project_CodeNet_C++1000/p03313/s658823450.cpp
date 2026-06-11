#include <bits/stdc++.h>
#define PII pair<int, int>
#define LL long long
using namespace std;
const int MAXN = 1 << 18;
const LL MOD = 1000000007;
const LL INF = (LL) 1e9 + 5;

int N, a[MAXN], dp1[MAXN], dp2[MAXN];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 0; i < (1 << N); i++) {
		cin >> a[i];
		dp1[i] = a[i];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < (1 << N); j++) {
			if (j >> i & 1) {
				int arr[4] = {dp1[j], dp2[j], dp1[j ^ 1 << i], dp2[j ^ 1 << i]};
				sort(arr, arr + 4);
				dp1[j] = arr[3];
				dp2[j] = arr[2];
			}
		}
	}
	int ans = 0;
	for (int i = 1; i < (1 << N); i++) {
		ans = max(ans, dp1[i] + dp2[i]);
		cout << ans << "\n";
	}

	return 0;
}