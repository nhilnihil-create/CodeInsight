#include<bits/stdc++.h>
 
using namespace std;
 
const int N = 2e5 + 10;
const int limit = 1e5 + 1;
 
int a[N], n;
long long res;
 
struct Fenwick_Tree {
	int s[N];
	void clear() {memset(s, 0, sizeof(s));}
	void update(int x, int y) {for(; x <= n + limit; x += x & -x) s[x] += y;}
	int query(int x) {int res = 0; for(; x; x -= x & -x) res += s[x]; return res;}
}T;
 
bool check(int x) {
	int sum = limit; res = 0;
	T.clear(); T.update(sum, 1);
	for(int i = 1; i <= n; ++ i) {
		sum += a[i] >= x ? 1 : -1;
		res += T.query(sum);
		T.update(sum, 1);
	}
	long long tot = 1ll * n * (n + 1) / 2;
	return res > (tot - (tot / 2 + 1));
}
 
int main() {
	int ans, l = 1, r = 1e9;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++ i)
		scanf("%d", &a[i]);
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(check(mid)) ans = mid, l = mid + 1;	
		else r = mid - 1;
	}
	printf("%d\n", ans);
	return 0;
}
