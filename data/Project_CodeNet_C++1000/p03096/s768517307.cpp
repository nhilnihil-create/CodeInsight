#pragma GCC optimize("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target ("avx")
#include <bits/stdc++.h>
constexpr int INF = 2147483647;
constexpr long long int INF_LL = 9223372036854775807;
constexpr int MOD = 1000000007;
constexpr double PI = 3.14159265358979323846;
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

int main() {
	int N;
	cin >> N;
	vector<int> C(N);
	for (int i = 0; i < N; i++) {
		cin >> C[i];
	}
	C.erase(unique(C.begin(), C.end()), C.end());
	vector<int> next(C.size(), -1);
	map<int, int> a;
	for (int i = C.size() - 1; i >= 0; i--) {
		try {
			next[i] = a.at(C[i]);
		}
		catch(...){
		}
		a[C[i]] = i;
	}
	vector<int> dp(C.size(), 0);
	dp[0] = 1;
	for (int i = 0; i < C.size(); i++) {
		if (next[i] != -1) {
			dp[next[i]] += dp[i];
			dp[next[i]] %= MOD;
		}
		dp[i + 1] += dp[i];
		dp[i + 1] %= MOD;
	}
	cout << dp.back() << endl;
}