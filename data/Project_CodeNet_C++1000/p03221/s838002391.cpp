
// C - ID

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

map<int, vector<int>> Y_list;
map<pair<int, int>, int> PY_to_idx;

int main() {
	int N, M;
	cin >> N >> M;

	for (int P=1; P<=N; P++) {
		Y_list[P] = vector<int>();
	}

	for (int i=0; i<M; i++) {
		int P, Y;
		cin >> P >> Y;
		Y_list[P].push_back(Y);
		PY_to_idx[make_pair(P, Y)] = i;
	}

	vector<string> ans(M);
	for (int P=1; P<=N; P++) {
		sort(Y_list[P].begin(), Y_list[P].end());

		for (int i=0; i<Y_list[P].size(); i++) {
			int Y = Y_list[P][i];
			char P_f[10], I_f[10];
			sprintf(P_f, "%06d", P);
			sprintf(I_f, "%06d", i+1);
			ans[PY_to_idx[make_pair(P, Y)]] = (string)P_f + (string)I_f;
		}
	}

	for (string a : ans) {
		cout << a << endl;
	}

	return 0;
}