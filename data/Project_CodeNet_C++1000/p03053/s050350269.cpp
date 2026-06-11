#include<iostream>
#include<algorithm>
#include<queue>
#include<string>
using namespace std;
int a[1010][1010];
int n, m;
string s;
queue<pair<int, int>>q;
int deep = 1, cnt = 0, len = 0;
void add(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < m) {
		if (a[x][y] == 0) {
			q.push({ x,y });
			a[x][y] = deep;
			++cnt;
		}
	}
}
int main() {
	int i, j;
	cin >> n >> m;
	for (i = 0; i < n; ++i) {
		cin >> s;
		for (j = 0; j < m; ++j) {
			if (s[j] == '#') {
				q.push({ i,j });
				a[i][j] = 1;
				++len;
			}
			else a[i][j] = 0;
		}
	}
	while (!q.empty()) {
		++deep;
		while (len--) {
			pair<int, int>t = q.front();
			q.pop();
			int x = t.first, y = t.second;
			add(x - 1, y), add(x + 1, y), add(x, y - 1), add(x, y + 1);
		}
		len = cnt;
		cnt = 0;
	}
	cout << deep - 2 << endl;
	return 0;
}