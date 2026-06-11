/*
─────────────────────
───────────████████──
──────────███▄███████
──────────███████████
──────────███████████
──────────██████─────
──────────█████████──
█───────███████──────
██────████████████───
███──████AJ████──█───
███████████████──────
███████████████──────
─█████████████───────
──███████████────────
────████████─────────
─────███──██─────────
─────██────█─────────
─────█─────█─────────
─────██────██────────
─────────────────────
*/

#include<bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long

vector<vector<int>> comp(21, vector<int>(21, 0));
int N;
ll mod = 1e9 + 7;
vector<vector<ll>> dp;

ll getMax(int index, int w) {
	// Function returns for index'th man and the woman left
	// in w how many ways can they be arranged
	// All men explored => index of man I'm currently on is == N

	if (index == N) {
		return (w != 0 ? 0 : 1);
	}

	if (dp[index][w] != -1) return dp[index][w];


	ll ans = 0;
	for (int i = 0; i < N; i++) {
		if (comp[index][i] && (((1 << i) & w) != 0)) {
			int v = w ^ (w & (1 << i));
			ans += getMax(index + 1, v) % mod;
		}
	}

	return dp[index][w] = (ans % mod);
}


int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> comp[i][j];
		}
	}
	dp = vector<vector<ll>> (N, vector<ll>(1 << N, -1));
	int w = (1 << N) - 1;
	ll result = getMax(0, w);
	cout << result << endl;
	return 0;
}