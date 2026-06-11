#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> vt;
int n, m, k;
void dfs(int x, int depth) {
	if (depth ==0)return;
	if (x - m >= depth) {
		for (int i = x - m + 1; i <= x;i++)
			vt.push_back(i);
		dfs(x - m, depth - 1);
	}
	else {
		for (int i = depth; i <= x; i++)
			vt.push_back(i);
		dfs(depth - 1, depth - 1);
	}
}
int main()
{
	scanf("%d %d %d", &n, &m, &k);
	int ch = n / m;
	if (n%m)ch++;
	if (n+1 < m + k) {
		puts("-1");
		return 0;
	}
	if (k < ch) {
		puts("-1");
		return 0;
	}
	dfs(n, k);
	for (int i = 0; i < vt.size(); i++)
		printf("%d ", vt[i]);
}