#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <queue>
#include <climits>
#define rep(i,n) for (int i=0;i<(n);i++)

using namespace std;

vector<int> to[10005];

int main() {
	int h,w;
	cin >> h >> w;
	vector<vector<char>> zu(h + 2, vector<char>(w + 2));
	int count = 0;
	for (int i = 1;i <= h;i++) {
		for (int j = 1;j <= w;j++) {
			cin >> zu[i][j];
			if (zu[i][j] == '#') {
				count++;
			}
		}
	}

	for (int i = 1;i <= h;i++) {
		for (int j = 1;j <= w;j++) {
			if (zu[i][j] == '#') continue;

			if (zu[i + 1][j] == '.')to[i * w + j].push_back((i + 1) * w + j);
			if (zu[i - 1][j] == '.')to[i * w + j].push_back((i - 1) * w + j);
			if (zu[i][j + 1] == '.')to[i * w + j].push_back(i * w + j + 1);
			if (zu[i][j - 1] == '.')to[i * w + j].push_back(i * w + j - 1);
		}
	}

	int start = 1 * w + 1;
	int goal = h * w + w;
	vector<int> dist(goal + 1, -1);
	queue<int> que;
	dist[start] = 1;
	que.push(start);

	while (!que.empty()) {
		int v = que.front();
		que.pop();

		for (int nv : to[v]) {
			if (dist[nv] != -1)continue;
			dist[nv] = dist[v] + 1;
			que.push(nv);
		}
	}

	if (dist[goal] == -1) {
		cout << -1 << endl;
		return 0;
	}

	int ans = 0;
	ans = h * w - dist[goal] - count;

	cout << ans << endl;

	return 0;
}
