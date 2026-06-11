#include "bits/stdc++.h"
using namespace std;

int main() {
	string S;
	int X, Y, count = 0;
	bool lr = true;
	vector<int> UD, LR;
	cin >> S >> X >> Y;
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == 'F') {
			count++;
		}
		else {
			if (lr) LR.push_back(count);
			else UD.push_back(count);
			count = 0;
			lr = !lr;
		}
	}
	if (lr) LR.push_back(count);
	else UD.push_back(count);
	static bool LR_DP[4010][16010] = {}, UD_DP[4010][16010] = {};
	LR_DP[0][8000 + LR[0]] = true;
	for (int i = 1; i < LR.size(); i++) {
		for (int j = 0; j <= 16000; j++) {
			if (j - LR[i] >= 0 && j + LR[i] <= 16000) LR_DP[i][j] = (LR_DP[i - 1][j - LR[i]] || LR_DP[i - 1][j + LR[i]]);
			else if (j - LR[i] >= 0) LR_DP[i][j] = LR_DP[i - 1][j - LR[i]];
			else if (j + LR[i] <= 16000) LR_DP[i][j] = LR_DP[i - 1][j + LR[i]];
		}
	}
	UD_DP[0][8000] = true;
	for (int i = 0; i < UD.size(); i++) {
		for (int j = 0; j <= 16000; j++) {
			if (j - UD[i] >= 0 && j + UD[i] <= 16000) UD_DP[i + 1][j] = (UD_DP[i][j - UD[i]] || UD_DP[i][j + UD[i]]);
			else if (j - UD[i] >= 0) UD_DP[i + 1][j] = UD_DP[i][j - UD[i]];
			else if (j + UD[i] <= 16000) UD_DP[i + 1][j] = UD_DP[i][j + UD[i]];
		}
	}
	if (LR_DP[LR.size() - 1][X + 8000] && UD_DP[UD.size()][Y + 8000]) cout << "Yes";
	else cout << "No";
}