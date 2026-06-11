
#include <bits/stdc++.h>
#define mod 1000000007
#define mod998 998244353
#define sp ' '
#define intmax 2147483647
#define llmax 9223372036854775807
#define mkp make_pair
typedef long long ll;
using namespace std;

string S, T;
int K, res, DP[302][302][302];
int main() {
	cin >> S >> K;
	T = S;
	reverse(T.begin(), T.end());
	for (int i = 0; i <= K; i++) {
		for (int j = 0; j < S.size(); j++) {
			for (int k = 0; k < T.size(); k++) {
				if (S[j] == T[k]) {
					DP[j + 1][k + 1][i] = max(DP[j + 1][k + 1][i], DP[j][k][i] + 1);
				}
				DP[j + 1][k][i] = max(DP[j + 1][k][i], DP[j][k][i]);
				DP[j][k + 1][i] = max(DP[j][k + 1][i], DP[j][k][i]);
				DP[j + 1][k + 1][i + 1] = max(DP[j + 1][k + 1][i + 1], DP[j][k][i] + 1);
			}
		}
	}
	res = 1;
	for (int i = 1; i < S.size(); i++) {
		res = max(res, DP[i][S.size() - i][K] * 2);
		res = max(res, DP[i][S.size() - i - 1][K] * 2 + 1);
	}
	cout << res << endl;
}