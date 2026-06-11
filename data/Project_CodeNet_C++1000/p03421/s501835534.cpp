#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> vt;
int n, m, k;
void dfs(int x, int depth) {
	if (depth == k + 1)return;
	if(x-m>=k-depth){
		for (int i = x - m + 1; i <= x; i++)
			vt.push_back(i);
		dfs(x - m, depth + 1);
	}
	else if (x == k - depth + 1) {
		vt.push_back(x);
		dfs(x - 1, depth + 1);
	}
	else {
		int xx = k - depth;
		for (int i = xx + 1; i <= x; i++)
			vt.push_back(i);
		dfs(xx, depth + 1);
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
	dfs(n, 1);
	for (int i = 0; i < vt.size(); i++)
		printf("%d ", vt[i]);
}	