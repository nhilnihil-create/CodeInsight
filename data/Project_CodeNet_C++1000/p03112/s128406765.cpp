#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

void chmin(int64_t& a, int64_t b) {
	if (a > b) a = b;
}

int main() {
	int64_t A, B, Q;
	cin >> A >> B >> Q;

	vector<int64_t> S(A), T(B);
	for (int i = 0; i < A; i++) cin >> S[i];
	for (int i = 0; i < B; i++) cin >> T[i];

	for (int i = 0; i < Q; i++) {
		int64_t x;
		cin >> x;
		//cout << "x:" << x << endl;

		int64_t s_itr, t_itr;
		s_itr = upper_bound(S.begin(), S.end(), x) - S.begin();
		t_itr = upper_bound(T.begin(), T.end(), x) - T.begin();
		if (s_itr == A) s_itr--;
		if (t_itr == B) t_itr--;

		int64_t ans = INT64_MAX;

		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				int64_t s, t;
				s = max((int64_t)0, s_itr - j);
				t = max((int64_t)0, t_itr - k);

				int64_t n, m;
				n = abs(S[s] - x) + abs(S[s] - T[t]);
				m = abs(T[t] - x) + abs(S[s] - T[t]);

				chmin(ans, n);
				chmin(ans, m);
			}
		}

		cout << ans << endl;
	}
}