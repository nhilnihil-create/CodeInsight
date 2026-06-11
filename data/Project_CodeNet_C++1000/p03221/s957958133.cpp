
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

	for (int i=0; i<M; i++) {
		int P, Y;
		cin >> P >> Y;
		Y_list[P].push_back(Y);
		PY_to_idx[make_pair(P, Y)] = i;
	}

	vector<string> ans(M);
	for (auto itr : Y_list) {
		int P = itr.first;
		vector<int>& Y_list = itr.second;
		sort(Y_list.begin(), Y_list.end());

		for (int i=0; i<Y_list.size(); i++) {
			int Y = Y_list[i];
			int I = i+1;
			char P_formatted[10], I_formatted[10];
			sprintf(P_formatted, "%06d", P);
			sprintf(I_formatted, "%06d", I);
			ans[PY_to_idx[make_pair(P, Y)]] = (string)P_formatted + (string)I_formatted;
		}
	}

	for (string a : ans) {
		cout << a << endl;
	}

	return 0;
}