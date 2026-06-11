#pragma GCC optimize("Ofast", "unroll-loops")

// #define TEST

#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
	int N; cin >> N;
	string S; cin >> S;
	vector<int> M_cnt(N + 1, 0), C_cnt(N + 1, 0);
	vector<ll> MC_cnt(N + 1, 0);
	vector<int> D_idx;
	for (int i = 0; i < N; ++i) {
		M_cnt[i + 1] = M_cnt[i];
		C_cnt[i + 1] = C_cnt[i];
		MC_cnt[i + 1] = MC_cnt[i];
		if (S[i] == 'D')
			D_idx.push_back(i);
		else if (S[i] == 'M')
			++M_cnt[i + 1];
		else if (S[i] == 'C') {
			++C_cnt[i + 1];
			MC_cnt[i + 1] += M_cnt[i + 1];
		}
	}
#ifdef TEST
	cout << "------M_cnt-----" << endl;
	for (auto i : M_cnt) cout << i << " ";
	cout << endl;
	cout << "------C_cnt-----" << endl;
	for (auto i : C_cnt) cout << i << " ";
	cout << endl;
	cout << "------MC_cnt-----" << endl;
	for (auto i : MC_cnt) cout << i << " ";
	cout << endl;
	cout << "------D_idx-----" << endl;
	for (auto i : D_idx) cout << i << " ";
	cout << endl;
#endif
	int Q; cin >> Q;
	while (Q--) {
		int k; cin >> k;
		ll res = 0;
		for (auto d : D_idx) {
			ll tmp = MC_cnt[min(N, d + k)] - MC_cnt[d];
			tmp -= ((ll)C_cnt[min(N, d + k)] - C_cnt[d]) * M_cnt[d];
			res += tmp;
		}
		cout << res << endl;
	}
	return 0;
}