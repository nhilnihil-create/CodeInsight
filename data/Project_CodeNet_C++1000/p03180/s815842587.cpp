#include <bits/stdc++.h>
using namespace std;

const int MXN = (1 << 4);

int n, in[MXN][MXN];
long long dp[1 << MXN], pp[1 << MXN];

void npt() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> in[i][j];
		}
	}
}

void rec(int i, const vector<int>& nt, long long sc, int msk, int gp) {
	if (i == (int) nt.size()) {
		dp[msk] = max(dp[msk], sc + pp[gp]);
		return ;
	}
	rec(i + 1, nt, sc, msk, gp);
	rec(i + 1, nt, sc, msk ^ (1 << nt[i]), gp ^ (1 << nt[i]));
}

void slv() {
	for (int i = 1; i <= n; i++)
		dp[i] = INT_MIN;
	dp[0] = 0;
	for (int msk = 0; msk < (1 << n); msk++)
		for (int i = 0; i < n; i++)
			if (msk & (1 << i))
				for (int j = i + 1; j < n; j++)
					if (msk & (1 << j))
						pp[msk] += in[i][j];
	for (int msk = 0; msk < (1 << n); msk++) {
		vector<int> nt;
		for (int i =  0; i < n; i++)
			if (!(msk &  (1 << i)))
				nt.push_back(i);
		rec(0, nt, dp[msk], msk, 0);
	}
}

void tpt() {
	cout << dp[(1 << n) - 1] << endl;
}

int main() {
	npt();
	slv();
	tpt();
	return 0;
}
