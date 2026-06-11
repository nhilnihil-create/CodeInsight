	// cout << endl;
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
#define mod 1000000007

vector<vector<int>> adj;
int N;
vector<pair<ll, ll>> dp;

pair<ll, ll> getWays(int node, int parent) {
	if (adj[node].size() == 1 && parent != 0) {
		return make_pair(1, 1);
	}
	if (dp[node].first != -1) return dp[node];
	ll white = 1, black = 1;
	for (int i = 0; i < adj[node].size(); i++) {
		int child = adj[node][i];
		if (child != parent) {
			pair<ll, ll> res = getWays(child, node);
			white = (white * (res.first + res.second)) % mod;
			black = (black * res.first) % mod;
		}
	}
	return dp[node] = make_pair(white, black);
}

int main() {
	cin >> N;
	adj = vector<vector<int>> (N + 1);
	dp = vector<pair<ll, ll>> (N + 1, make_pair(-1, -1));
	int x, y;
	for (int i = 0; i < N - 1; i++) {
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	pair<ll, ll> res = getWays(1, 0);
	cout << (res.first + res.second) % mod << endl;
	return 0;
}