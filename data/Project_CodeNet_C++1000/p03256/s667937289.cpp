#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	string s(n, ' ');
	scanf("%s", s.data());

	vector<vector<int>> graph(n);
	vector<array<int, 2>> cnt(n);

	while (m--) {
		int a, b;
		scanf("%d %d", &a, &b); a--; b--;
		graph[a].push_back(b);
		graph[b].push_back(a);
		cnt[a][s[b]-'A']++;
		cnt[b][s[a]-'A']++;
	}

	vector<int> rem;
	vector<bool> removed(n, false);
	for (int i = 0; i < n; i++)
		if (cnt[i][0] == 0 || cnt[i][1] == 0) {
			removed[i] = true;
			rem.push_back(i);
		}

	for (int i = 0; i < rem.size(); i++) {
		int x = rem[i];

		int inx = s[x] - 'A';
		
		for (int y : graph[x]) {
			if ((--cnt[y][inx]) == 0 && !removed[y]) {
				removed[y] = true;
				rem.push_back(y);
			}
		}
	}

	if (rem.size() == n) printf("No\n");
	else printf("Yes\n");

	return 0;
}