#pragma GCC optimize("Ofast", "unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int N;
vector<int> A;

void input(void){
	cin >> N;
	A.resize(1 << N);
	for (auto& ai : A)
		cin >> ai;
}

using tiiii = tuple<int, int, int, int>;

tiiii merge(tiiii a, tiiii b){
	using pii = pair<int, int>;
	set<pii> st;
	st.insert({get<0>(a), get<1>(a)});
	st.insert({get<2>(a), get<3>(a)});
	st.insert({get<0>(b), get<1>(b)});
	st.insert({get<2>(b), get<3>(b)});
	vector<pii> res;
	for (auto p : st)
		res.push_back(p);
	reverse(res.begin(), res.end());
	return make_tuple(res[0].first, res[0].second, res[1].first, res[1].second);
}

int sum(tiiii t){
	return get<0>(t) + get<2>(t);
}

vector<int> solve(void){
	vector<vector<tiiii>> dp(1 << N, vector<tiiii>(N + 1));
	// 初期化
	for (int i = 0; i < (1 << N); ++i)
		dp[i][0] = make_tuple(A[i], i, 0, -1);
	// 遷移
	for (int j = 0; j < N; ++j){
		for (int i = 0; i < (1 << N); ++i){
			if (i & (1 << j))
				dp[i][j + 1] = merge(dp[i & ~(1 << j)][j], dp[i][j]);
			else dp[i][j + 1] = dp[i][j];
		}
	}
	vector<int> res(1 << N);
	res[0] = sum(dp[0][N]);
	for (int i = 1; i < (1 << N); ++i)
		res[i] = max(res[i - 1], sum(dp[i][N]));
	return res;
}

int main(void){
	input();
	vector<int> res = solve();
	for (int i = 1; i < (1 << N); ++i)
		cout << res[i] << endl;
	return 0;
}