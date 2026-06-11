
// D - Match Matching

// DFSを用いる解法

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int N, M;
vector<pair<int, int>> A;
int m[10] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
string k;
string ans;
int ans_len = -1;

bool dfs(int n) {
	// 最初の候補が見つかったら最後の2桁だけ全探索して終了
	if ((int)k.size() < ans_len - 3) return true;

	if (n == 0) {
		ans_len = max(ans_len, (int)k.size());

		string tmp_k = k;
		sort(tmp_k.begin(), tmp_k.end(), greater<char>());

		if (k.size() == ans_len && tmp_k > ans) {
			ans = tmp_k;
		}

		return false;
	}

	if (n < 0) return false;

	for (auto a : A) {
		k.push_back('0' + a.second);
		if (dfs(n - a.first)) return true;
		k.pop_back();
	}

	return false;
}

int main() {
	cin >> N >> M;

	for (int i=0; i<M; i++) {
		int a;
		cin >> a;
		A.push_back(make_pair(m[a], -a));
	}

	sort(A.begin(), A.end());

	for (int i=0; i<M; i++) {
		A[i] = make_pair(A[i].first, -A[i].second);
	}

	dfs(N);

	cout << ans << endl;

	return 0;
}
