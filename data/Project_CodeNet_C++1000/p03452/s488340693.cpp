#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#define MN 100005
#define INF 1000000007
#define IMP 2147483647
#define pp pair<int,int>
using namespace std;
vector<pp> rel[MN];
int n,m;
int w[MN];
bool chk[MN];
bool ans;
void dfs(int x) {
	chk[x] = true;
	if (w[x] == IMP) w[x] = 0;
	for (auto next : rel[x]) {
		int y=next.first, d=next.second;
		if (w[y] != IMP && w[y] != w[x] + d) ans = false;
		if (!chk[y]) {
			w[y] = w[x] + d;
			dfs(y);
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	ans = true;
	int i;
	for (i = 1; i <= n; i++) w[i] = IMP;
	for (i = 1; i <= m; i++) {
		int l, r, d;
		scanf("%d%d%d", &l, &r, &d);
		rel[l].push_back({ r,d });
		rel[r].push_back({ l,-d });
	}
	for (i = 1; i <= n; i++) {
		if (!chk[i]) dfs(i);
	}
	if (ans) printf("Yes");
	else printf("No");
	return 0;
}