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
int n;
vector<vector<int>> vec(10010);
vector<int> m, a, b;
bool bo[10010] = { false };
int ans[100010];
int main() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a1, b1;
		cin >> a1 >> b1;
		a.emplace_back(a1);
		b.emplace_back(b1);
		vec[a1].emplace_back(b1);
		vec[b1].emplace_back(a1);
	}
	for (int i = 0; i < n; i++) {
		int m1;
		cin >> m1;
		m.emplace_back(m1);
	}
	sort(m.rbegin(), m.rend());
	queue<int> que;
	que.push(1);
	bo[1] = true;
	ans[1] = m[0];
	int now = 1;
	while (!que.empty()) {
		int t = que.front();
		for (int i = 0; i < vec[t].size(); i++) {
			if (!bo[vec[t][i]]) {
				que.push(vec[t][i]);
				ans[vec[t][i]] = m[now];
				now++;
				bo[vec[t][i]] = true;
			}
		}
		que.pop();
	}
	int sum = 0;
	for (int i = 0; i < n - 1; i++) {
		sum += min(ans[a[i]], ans[b[i]]);
	}
	cout << sum << endl;
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
}
