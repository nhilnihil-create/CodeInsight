#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>

#define DIV 1000000007

using namespace std;
using ll = long long;
using ldb = long double;

typedef struct {
	ll x, y, z;
}cake_t;

int main() {
	ll N, M; cin >> N >> M;
	vector<cake_t> cake(N);
	for (int i = 0; i < N; i++) {
		cin >> cake[i].x >> cake[i].y >> cake[i].z;
	}
	ll ans = -1e14;
	for (int i = 0; i < 8; i++) {
		ll an = 0;
		int temp = i;
		vector<int> bit(3);
		vector<ll> scr(N);
		for (int j = 0; temp > 0; j++) {
			bit[j] = temp % 2;
			temp /= 2;
		}
		for (int k = 0; k < N; k++) {
			if (bit[0]) scr[k] += cake[k].x;
			else scr[k] -= cake[k].x;

			if (bit[1]) scr[k] += cake[k].y;
			else scr[k] -= cake[k].y;

			if (bit[2]) scr[k] += cake[k].z;
			else scr[k] -= cake[k].z;
		}
		sort(scr.begin(), scr.end(), greater<ll>());
		for (int k = 0; k < M; k++) {
			an += scr[k];
		}
		ans = max(ans, an);
	}

	cout << ans << endl;
}
