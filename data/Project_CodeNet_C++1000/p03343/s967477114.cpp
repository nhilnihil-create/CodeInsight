#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
	int N, K, Q;
	cin >> N >> K >> Q;
	vector<ll> A(N);
	for (int i = 0; i < N; ++i) { cin >> A[i]; }

	ll res = 1e18;
	for (int i = 0; i < N; ++i) {
		vector<ll> use;
		int l = -1, r = 0;
		while (r < N) {
			while ((r < N) && (A[r] >= A[i])) { ++r; }

			int len = r - l - 1;
			vector<ll> tmp(len);
			if (len >= K) {
				for (int j = l + 1; j < r; ++j) {
					tmp[j - l - 1] = A[j];
				}
				sort(tmp.begin(), tmp.end());
				for (int j = 0; j < (len - K + 1); ++j) {
					use.push_back(tmp[j]);
				}
			}
			l = r;
			++r;
		}
		
		if (use.size() >= Q) {
			sort(use.begin(), use.end());
			ll tmp = use[Q - 1] - use[0];
			res = min(res, tmp);
		}
	}

	cout << res << endl;

	return 0;
}
