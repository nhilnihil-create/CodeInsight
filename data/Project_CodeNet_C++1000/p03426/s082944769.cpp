#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>
#include<tuple>

#define DIV 998244353
using namespace std;
using ll = long long;
using ldb = long double;

int main() {
	int H, W, D; cin >> H >> W >> D;
	vector<vector<int>> grid(H, vector<int>(W));
	map<int,pair<int, int>> mp;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> grid[i][j];
			mp[grid[i][j]] = make_pair(i, j);
		}
	}


	vector<vector<int>> cost(H * W + 1);
	for (int i = 0; i <= D - 1; i++) {
		int cnt = 1;
		cost[i].push_back(0);
		while (i + cnt * D <= H * W) {
			//cout << "cnt=" << cnt << endl;
			int now = i + cnt * D, len = cost[i].size();
			cost[i].push_back( cost[i][len-1] 
				+ abs(mp[now - D].first - mp[now].first) + abs(mp[now - D].second - mp[now].second));
			cnt++;
		}
	}

	int Q; cin >> Q;
	for (int i = 0; i < Q; i++) {
		int L, R; cin >> L >> R;
		int se = L % D;
		L /= D, R /= D;
		cout << cost[se][R] - cost[se][L] << endl;
	}

}
