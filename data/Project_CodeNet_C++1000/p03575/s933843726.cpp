#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <deque>
#include <cstdio>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <cctype>
using namespace std;
int main() {
	int n, m;
	int a[100], b[100];
	cin >> n >> m;
	vector<vector<int>>vec(100);
	for (int i = 0; i < m; i++) {
		cin >> a[i] >> b[i];
		vec[a[i]].emplace_back(b[i]);
		vec[b[i]].emplace_back(a[i]);
	}
	queue<int> que;
	int ans = 0;
	for (int j = 0; j < m; j++) {
		que.push(1);
		bool bo[100] = { false };
		bo[1] = true;
		int co = 0;
		while (!que.empty()) {
			int now = que.front();
			for (int i = 0; i < vec[now].size(); i++) {
				if (bo[vec[now][i]] == false) {
					if (now != a[j] || vec[now][i] != b[j]) {
						if (now != b[j] || vec[now][i] != a[j]) {
							que.push(vec[now][i]);
							bo[vec[now][i]] = true;
							co++;
						}
					}
				}
			}
			que.pop();
		}
		if (co != n - 1) {
			ans++;
		}
	}
	cout << ans << endl;
}

