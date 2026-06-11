#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using Graph = vector<vector<int>>;
const int MOD = 1e9 + 7;

inline int solve(pii a, pii b){
	return abs(a.first - b.first) + abs(a.second - b.second);
}

int main(){
	int H, W, D, Q;
	cin >> H >> W >> D;
	vector<pii> pos(H*W);
	for (int i = 0; i < H; ++i){
		for (int j = 0; j < W; ++j){
			int A;
			cin >> A;
			A--;
			pos[A] = make_pair(i, j);
		}
	}

	vector<ll> dist(H*W);
	for (int i = 0; i < H*W; ++i)
		if (i - D >= 0)
			dist[i] = dist[i - D] + solve(pos[i], pos[i - D]);

	cin >> Q;
	for (int i = 0; i < Q; ++i){
		int l, r;
		cin >> l >> r;
		l--, r--;
		cout << dist[r] - dist[l] << '\n';
	}

	return 0;
}