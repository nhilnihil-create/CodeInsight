#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int main() {
	int N, K;
	cin >> N >> K;

	vector<int> v(N);
	for (int i = 0; i < N; i++) cin >> v[i];
	sort(v.begin(), v.end());

	int ans = INF;
	for (int i = 0; i < N - K + 1; i++) {
		int n = v[i + K - 1] - v[i];
		ans = min(ans, n);
	}

	cout << ans << endl;
}