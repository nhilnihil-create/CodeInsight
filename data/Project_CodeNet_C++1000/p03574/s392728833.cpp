#include"bits/stdc++.h"

#define rep(i, N) for(int i = 0;i < N;i++)

typedef long long ll;

const int mod = 1e9 + 7;

using namespace std;



int main(void) {
	int H, W; cin >> H >> W;
	vector<string> S(H);
	rep(i, H) {
		cin >> S[i];
	}

	rep(i, H)rep(j, W) {
		if (S[i][j] == '#')continue;

		S[i][j] = '0';
		for (int k = i - 1; k <= i + 1; k++)for (int l = j - 1; l <= j + 1; l++) {
			if (k < 0 || H <= k || l < 0 || W <= l)continue;
			if (S[k][l] == '#')S[i][j]++;
		}
	}

	for (auto x : S) {
		cout << x << endl;
	}

	return 0;
}
