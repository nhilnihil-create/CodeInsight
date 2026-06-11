#include<iostream>
#include<string>

using namespace std;

typedef long long ll;

string S;
ll ruisekiwa[100001][4];

ll dp[100001][4];

const ll MOD = 1000000007;

int main() {
	cin >> S;
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == 'A')ruisekiwa[i + 1][0]++;
		else if (S[i] == 'B')ruisekiwa[i + 1][1]++;
		else if (S[i] == 'C')ruisekiwa[i + 1][2]++;
		else if (S[i] == '?')ruisekiwa[i + 1][3]++;
		for (int j = 0; j < 4; j++) {
			ruisekiwa[i + 1][j] += ruisekiwa[i][j];
		}
	}

	dp[0][0] = 1;

	for (int i = 1; i <= S.size(); i++) {

		for (int j = 0; j < 4; j++) {
			if (S[i - 1] == '?')
				dp[i][j] += dp[i - 1][j] * 3;
			else
				dp[i][j] += dp[i - 1][j];
		}

		if (S[i - 1] == 'A' || S[i - 1] == '?') {
			dp[i][1] += dp[i - 1][0];
		}
		if (S[i - 1] == 'B' || S[i - 1] == '?') {
			dp[i][2] += dp[i - 1][1];
		}
		if (S[i - 1] == 'C' || S[i - 1] == '?') {
			dp[i][3] += dp[i - 1][2];
		}

		for (int j = 0; j < 4; j++) {
			dp[i][j] %= MOD;
		}
	}
	
	cout << dp[S.size()][3] << endl;

	return 0;
}