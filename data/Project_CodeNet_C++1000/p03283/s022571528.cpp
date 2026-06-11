#include <bits/stdc++.h>
using namespace std;

int	main()
{
	int	N, M, Q;
	cin >> N >> M >> Q;
	vector<vector<int>>	cnt_vec(N + 1, vector<int>(N + 1, 0));
	vector<int>	cnt_R_vec(N + 1, 0);
	int	L, R;
	for (int i = 0; i < M; ++i) {
		cin >> L >> R;
		cnt_vec.at(R).at(L) += 1;
		cnt_R_vec.at(R) += 1;
	}
	vector<vector<int>>	cumsum_vec(N + 1, vector<int>(N + 1, 0));
	vector<int>	cumsum_R(N + 1, 0);
	for (int i = 0; i < N; ++i)
		cumsum_R.at(i + 1) = cumsum_R.at(i) + cnt_R_vec.at(i + 1);
	for (int i = 1; i <= N; ++i) {
		for (int j = 0; j < N; ++j) {
			cumsum_vec.at(i).at(j + 1) = cumsum_vec.at(i).at(j);
			cumsum_vec.at(i).at(j + 1) += cnt_vec.at(i).at(j + 1);
		}
	}
	for (int j = 1; j <= N; ++j) {
		for (int i = 0; i < N; ++i) {
			cumsum_vec.at(i + 1).at(j) += cumsum_vec.at(i).at(j);
		}
	}
	int	p, q;
	for (int i = 0; i < Q; ++i) {
		cin >> p >> q;
		cout << cumsum_R.at(q) - cumsum_vec.at(q).at(p - 1) << endl;
	}
}
