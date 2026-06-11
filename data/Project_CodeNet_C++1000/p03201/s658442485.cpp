#include <bits/stdc++.h>
// 对于 x + y = 2^i 来说，如果 x < y 且 2^i-1 < y < 2^i
// 那么 x 唯一
// 转换成树结构：根节点是 y 它的父亲 x 唯一
// 即求整个森林中最多的无公共端点的边的数量
using namespace std;
const int maxn = 200005, inf = 1e9;
int n, a;
map<int, int> mp; // map 自动排序 使得能够从叶子结点往上找边
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		mp[a]++;
	}
	int res = 0;
	while (!mp.empty()) {
		map<int, int>::iterator it = mp.end();
		it--;
		int y = it->first;
		mp[y]--;
		if (mp[y] == 0) mp.erase(y);
		int i = 1;
		while (i <= y) i *= 2;
		// 求出最小的那个大于 y 的二次幂数
		int x = i - y;
		if (mp.find(x) != mp.end()) {
			res++;
			mp[x]--;
			if (mp[x] == 0) mp.erase(x);
		}
	}
	printf("%d", res);
	return 0;
}