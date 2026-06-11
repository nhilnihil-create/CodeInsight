#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <vector>
#define LL long long
using namespace std;
const LL Maxn = 100010;
LL n, a[Maxn];
LL siz[Maxn];
struct lnode {
	LL x, y;
}lis[Maxn]; LL ll;
queue <LL> q[2];
LL dis[Maxn];
vector <LL> vec[Maxn];
void dfs(LL x) {
	dis[x] = 0; siz[x] = 1;
	for(LL i = 0; i < vec[x].size(); i++){
		LL y = vec[x][i];
		dfs(y);
		dis[x] += dis[y]+siz[y];
		siz[x] += siz[y];
	}
}
struct pnode {
	LL num, x;
	bool operator<(const pnode &A) const { return x < A.x; }
}po[Maxn];
int main() {
	LL i, j, k;
	scanf("%lld", &n);
	for(i = 1; i <= n; i++) scanf("%lld", &po[i].x), po[i].num = i;
	sort(po+1, po+n+1);
	for(i = 1; i <= n; i++) a[i] = po[i].x;
	for(i = 1; i <= n; i++) siz[i] = 1;
	for(i = n; i >= 2; i--){
		int x = lower_bound(a+1, a+n+1, a[i]-n+2*siz[i]) - a;
		if(a[x] != a[i]-n+2*siz[i]){ printf("-1\n"); return 0; }
		ll++;
		lis[ll].x = x; lis[ll].y = i;
		siz[x] += siz[i];
	}
	for(i = 1; i <= ll; i++) vec[lis[i].x].push_back(lis[i].y);
	dfs(1);
	if(dis[1] != a[1]){ printf("-1\n"); return 0; }
	for(i = 1; i <= ll; i++) printf("%lld %lld\n", po[lis[i].x].num, po[lis[i].y].num);
	return 0;
}