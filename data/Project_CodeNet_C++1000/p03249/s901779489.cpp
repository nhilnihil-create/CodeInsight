#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<cmath>
#include<algorithm>
#define N 100005
using namespace std;
struct with {
	int w;
	long long d;
} dt[N];
map<long long, int> chk;
int n;
int parent[N],subn[N];
long long d[N];
long long sum[N];
bool cmp(with i, with j) {
	return i.d < j.d;
}
int main() {
	scanf("%d", &n);
	int i;
	for (i = 1; i <= n; i++) {
		scanf("%lld", &d[i]);
		dt[i].d = d[i]; dt[i].w = i;
		subn[i] = 1;
	}
	sort(dt + 1, dt + 1 + n, cmp);
	sort(d + 1, d + 1 + n);
	for (i = 1; i <= n; i++) chk[d[i]] = i;
	bool imp = false;
	for (i = n ; i >= 2; i--) {
		int adjacent=0;
		adjacent = chk[d[i] - n + 2 * subn[i]];
		parent[i] = adjacent;
		subn[adjacent]+=subn[i];
		if (parent[i] == 0 || parent[i]==i) {
			imp = true; break;
		}
	}
	for (i = n; i >= 2; i--) {
		int up = parent[i];
		sum[up] += sum[i] + subn[i];
	}
	if (sum[1] != d[1]) imp = true;
	if (imp) printf("-1");
	else {
		for (i = 2; i <= n; i++) {
			printf("%d %d\n", dt[parent[i]].w,dt[i].w);
		}
	}
	return 0;
}