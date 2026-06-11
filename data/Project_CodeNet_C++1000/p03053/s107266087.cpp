#pragma region template
#include "bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD = 1e9 + 7, MAX = 1e18, larg = 1e5, INF = -1e9;
long long A, B, C, D, E, F, G, H, I, J, K, L, N, M, O, P, Q, R, S, T, U, V, W, x, y, z;
long long max_value = INF, max_index = -1;
long long min_value = MAX, min_index = -1;
typedef long long ll;
typedef pair<ll, ll> Pa;

char mp[1000][1000];
ll val[1000][1000];

int main() {
	cin >> H >> W;
	queue<Pa> que;
	rep(i, H) {
		rep(j, W) {
			cin >> mp[i][j];
			if (mp[i][j] == '#') {
				que.push(Pa(i, j));
				val[i][j] = 0;
			}
		}
	}
	int dx[4] = { 0, 1, 0, -1 }, dy[4] = { 1, 0, -1, 0 };
	ll ans = 0;
	while (!que.empty()) {
		Pa curr = que.front(); que.pop();
		int x = curr.second, y = curr.first;
		rep(j, 4) {
			int next_x = x + dx[j], next_y = y + dy[j];
			if (0 <= next_x && next_x < W && 0 <= next_y && next_y < H && mp[next_y][next_x] != '#') {
				que.push(Pa(next_y, next_x));
				val[next_y][next_x] = val[y][x] + 1;
				mp[next_y][next_x] = '#';
			}
		}
	}
	rep(i, H) {
		rep(j, W) {
			ans = max(ans, val[i][j]);
		}
	}
	cout << ans;
}