#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstring>
#include <list>
#include <unordered_set>
#include <tuple>
#include <cmath>
#include <limits>
#include <type_traits>
#include <iomanip>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <set>
#include <bitset>
#include <regex>
#include <random>
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define rep(i,n)for(ll i=0;i<n;++i)
#define exout(x) printf("%.10f\n", x)
const double pi = acos(-1.0);
const ll MOD = 1000000007;
const ll INF = 1e10;
const ll MAX_N = 1010;

//組み合わせの余りを求める
ll fac[MAX_N], finv[MAX_N], inv[MAX_N];

void COMinit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < MAX_N; i++) {
		fac[i] = fac[i - 1] * i;
	}
}

// 二項係数計算
long long COM(ll n, ll k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	if (n > k * 2) {

	}
	return fac[n] / (fac[k] * fac[n - k]);
}

ll dx[4] = { 0,0,-1,1 };
ll dy[4] = { -1,1,0,0 };
vector<vector<ll>>tree;
char c[505][505];
ll dist[505][505];
bool flag[505][505];
ll h, w;
ll sx, sy, gx, gy;
vector<ll>L;
queue<pair<ll, ll>>que;

void bfs() {
	while (!que.empty()) {
		pair<ll, ll> target = que.front();
		ll y = target.first;
		ll x = target.second;
		que.pop();
		rep(i, 4) {
			ll ny = y + dy[i];
			ll nx = x + dx[i];
			if (c[ny][nx] != '#') {
				if (0 <= ny && ny < h && 0 <= nx && nx < w&&flag[ny][nx]==false) {
					que.push(make_pair(ny, nx));
					dist[ny][nx] = dist[y][x] + 1;
					flag[ny][nx] = true;
				}
			}
		}
	}
}

//long longしか使わない
//素数は1より大きい
//lower_boundは指定したkey以上の要素の一番左のイテレータをかえす
//upper_boundは指定したkeyより大きい要素の一番左のイテレータをかえす
int main() {
	cin >> h >> w;
	ll white = 0;
	rep(i, h) {
		rep(j, w) {
			cin >> c[i][j];
			if (c[i][j] == '.')white++;
		}
	}
	que.push(make_pair(0, 0));
	bfs();
	ll total = white - dist[h - 1][w - 1] - 1;
	if (dist[h - 1][w - 1] == 0) {
		cout << -1 << endl;
		return 0;
	}
	cout << total << endl;
	return 0;
}
