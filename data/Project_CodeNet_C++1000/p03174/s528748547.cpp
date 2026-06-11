#include <bits/stdc++.h>
using namespace std;

const int MAX_NB = 22, MOD = 1e9+7;

int main() {
	int nbPersonne;
	cin >> nbPersonne;

	bool comp[nbPersonne][nbPersonne];

	for(int i = 0; i < nbPersonne; i++) {
		for(int j = 0; j < nbPersonne; j++) {
			cin >> comp[i][j];
		}
	}

	int dp[(1 << MAX_NB)] = {0};
	dp[0] = 1;

	for(int mask = 1; mask < (1 << nbPersonne); mask++) {
		for(int bitEnleve = 0; bitEnleve < MAX_NB; bitEnleve++) {
			int rang = __builtin_popcount(mask)-1;
			if(mask & (1 << bitEnleve) && comp[rang][bitEnleve]) {
				dp[mask] += (dp[mask - (1 << bitEnleve)]);
				dp[mask] %= MOD;
			}
		}
	}

	cout << dp[(1 << nbPersonne)-1];
}