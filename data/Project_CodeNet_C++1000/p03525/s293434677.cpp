#include <bits/stdc++.h>

using namespace std;

using ll = int64_t;
using Vi = vector<int>;
using Vl = vector<ll>;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

constexpr int I_INF = 2147483647;
constexpr ll L_INF = 9223372036854775807LL;

//===




int main()
{
	int N;
	cin >> N;
	Vi D(N);
	for (int i = 0; i < N; ++i) {
		cin >> D[i];
	}

	sort(D.begin(), D.end());

	Vi time(N + 1);
	for (int i = 0; i < N; ++i) {
		if (i % 2 == 0) {
			time[i + 1] = D[i];
		}
		else {
			time[i + 1] = -D[i];
		}
	}

	int ans = I_INF;
	for (int i = 0; i < N; ++i) {
		for (int j = i + 1; j < N + 1; ++j) {
			int diff = abs(time[i] - time[j]);
			diff = min(diff, 24 - diff);
			ans = min(ans, diff);
		}
	}

	cout << ans << endl;

	return 0;
}