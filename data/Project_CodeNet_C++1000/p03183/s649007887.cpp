#include <bits/stdc++.h>
#define INFLL (0x3f3f3f3f3f3f3f3fll)
using namespace std;
typedef long long ll;

const int MAXN = 1055;

ll dp[20055];

int A[MAXN], B[MAXN], C[MAXN], O[MAXN];

int N;

int main() {
	ios::sync_with_stdio(false);

	cin >> N;
	for(int i = 1; i <= N; i++) cin >> A[i] >> B[i] >> C[i];
	iota(O, O+N+1, 0); sort(O+1, O+N+1, [&](int a, int b) {
		return A[a]+B[a] < A[b]+B[b];
	});

	fill(dp+1, dp+20055, -INFLL);
	for(int oi = 1, i; oi <= N; oi++) {
		i = O[oi];
		for(int j = B[i]; 0 <= j; j--) {
			ll t = dp[j] + C[i];
			if(dp[j+A[i]] < t) dp[j+A[i]] = t;
		}
	}

	cout << *max_element(dp, dp+20055) << endl;
	return 0;
}