#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cctype>
#include<iostream>
#include<string>
#include<sstream>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>
#include<utility>
using namespace std;

#define ran 200020
int n, m, cntA[ran], cntB[ran];
vector<int> e[ran];
char s[ran];
queue<int> q;
bool inq[ran];
int main() {
	scanf("%d%d%s", &n, &m, s + 1);
	while (m--) {
		int x, y;
		scanf("%d%d", &x, &y);
		e[x].push_back(y);
		e[y].push_back(x);
		if (s[x] == 'A') cntA[y] ++;else
			cntB[y]++;
		if (s[y] == 'A') cntA[x] ++;else
			cntB[x]++;
	}
	for(int i=1; i<=n; i++)
		if (cntA[i] == 0 || cntB[i] == 0) {
			q.push(i);
			inq[i] = true;
		}
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (auto y : e[x]) {
			if (s[x] == 'A') {
				if (--cntA[y] == 0) {
					if (!inq[y]) {
						q.push(y);
						inq[y] = true;
					}
				}
			}
			else {
				if (--cntB[y] == 0) {
					if (!inq[y]) {
						q.push(y);
						inq[y] = true;
					}
				}
			}
		}
	}
	for (int i = 1; i <= n; i++)if (!inq[i]) {
		puts("Yes");
		return 0;
	}
	puts("No");
	return 0;
}