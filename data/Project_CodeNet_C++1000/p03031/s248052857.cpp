#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	vector <int> k(M);
	vector<vector<int>> s(M);
	for (int ii = 0; ii < M; ++ii){
		cin >> k[ii];
		for (int jj = 0; jj < k[ii]; ++jj){
			int tmp;
			cin >> tmp;
			tmp--;
			s[ii].push_back(tmp);
		}
	}

	vector <int> p(M);
	for (int ii = 0; ii < M; ++ii){
		cin >> p[ii];
	}

	int ans = 0;
	for (int n = 0; n < (1<<N); ++n){
		//スイッチの状態
		vector <int> t(N);
		for (int ii = 0; ii < N; ++ii){
			t[ii] = (n>>ii)&1;
		}

		// printf("n = %i\n", n);
		// for (int ii = 0; ii < N; ++ii){
		// 	printf(" %i ", t[ii]);
		// }
		// printf("\n");

		//つくかチェック
		bool ok = true;
		for (int ii = 0; ii < M; ++ii){
			int val = 0;
			for (int jj = 0; jj < k[ii]; ++jj){
				int idx = s[ii][jj];
				// printf("  idx[%i] %i\n", jj, idx);
				val += t[idx];
			}
			// printf("   ii %i, val %i\n", ii, val);
			if (val%2 != p[ii]){
				ok = false;
				break;
			}
		}

		if (ok){
			ans++;
		}
	}

	cout << ans << "\n";

	return 0;
}
