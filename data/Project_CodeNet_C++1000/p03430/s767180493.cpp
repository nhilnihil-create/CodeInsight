#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char a[321];
int n, K;
int d[321][321][321];
bool v[321][321][321];
int dfs(int s, int len, int edits)
{
	if (len == 0) return 0;
	if (len == 1) return 1;
	if (v[s][len][edits]) return d[s][len][edits];
	int e = s + len - 1;
	if (a[s] == a[e]) return dfs(s + 1, len - 2, edits) + 2;
	int ret = max(dfs(s, len - 1, edits), dfs(s + 1, len - 1, edits));
	if (edits < K)
		ret = max(ret, dfs(s + 1, len - 2, edits + 1) + 2);
	v[s][len][edits] = true;
	return d[s][len][edits] = ret;
}
int main()
{
	scanf("%s%d", &a[1], &K);
	n = strlen(&a[1]);
	printf("%d\n", dfs(1, n, 0));
	return 0;
}
