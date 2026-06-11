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
	for (int i = 0; i < N; i++) {
		cin >> v.at(i);
	}

	int ans = INT_MAX;
	for (int i = 0; i < N - K + 1; i++) {
		int L, R;
		L = v.at(i);
		R = v.at(i + K - 1);

		int dist = 0;
		if ((L < 0) && (R > 0)) {
			dist = min(abs(L), abs(R)) * 2 + max(abs(L), abs(R));
		}
		else {
			if (R < 0) dist = abs(L);
			else dist = abs(R);
		}

		ans = min(ans, dist);
	}

	cout << ans << endl;
}