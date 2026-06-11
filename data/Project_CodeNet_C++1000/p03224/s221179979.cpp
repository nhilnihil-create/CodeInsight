# include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn(1e5 + 5);

int n, k;
vector <int> st[maxn];

int main() {
	scanf("%d", &n);
	for (k = 1; ; ++k) if ((k * (k - 1) >> 1) > n) break;
	--k;
	if (n != (k * (k - 1) >> 1)) return puts("No"), 0;
	puts("Yes"), printf("%d\n", k);
	register int i, j, t = 0, l;
	for (i = 1; i <= k; ++i)
		for (j = i + 1; j <= k; ++j)
			st[i].push_back(++t), st[j].push_back(t);
	for (i = 1; i <= k; ++i, puts("")) {
		printf("%d ", l = st[i].size());
		for (j = 0; j < l; ++j) printf("%d ", st[i][j]);
	}
    return 0;
}