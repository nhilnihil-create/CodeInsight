#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll MOD = 1000000007LL;
ll A[200000];
ll B[200000];
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i] >> B[i];
	bool same = 1;
	ll sum = 0;
	for (int i = 0; i < N; i++) {
		if (A[i] != B[i]) same = 0;
		sum += A[i];
	}
	if (same) {
		cout << 0 << endl;
		return 0;
	}
	ll ans = 0;
	for (int i = 0; i < N; i++) {
		if (A[i] > B[i]) {
			ans = max(ans, sum - A[i] + (A[i] - B[i]));
		}
	}
	cout << ans << endl;
}