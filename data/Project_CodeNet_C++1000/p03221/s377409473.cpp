
// C - ID

// 座標圧縮の考え方による解法

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int P[100000];
int Y[100000];
map<int, vector<int>> Y_list;

int main() {
	int N, M;
	cin >> N >> M;

	for (int i=0; i<M; i++) {
		cin >> P[i] >> Y[i];
		Y_list[P[i]].push_back(Y[i]);
	}

	for (auto& itr : Y_list) {
		sort(itr.second.begin(), itr.second.end());
	}

	vector<string> ans(M);

	for (int i=0; i<M; i++) {
		int I = lower_bound(Y_list[P[i]].begin(), Y_list[P[i]].end(), Y[i]) - Y_list[P[i]].begin();
		char P_formatted[10], I_formatted[10];
		sprintf(P_formatted, "%06d", P[i]);
		sprintf(I_formatted, "%06d", I + 1);
		ans[i] = (string)P_formatted + (string)I_formatted;
	}

	for (string a : ans) {
		cout << a << endl;
	}

	return 0;
}