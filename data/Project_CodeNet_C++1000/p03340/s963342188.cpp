#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+5;
int prenum[maxn],prexor[maxn];
long long ans,n;

bool check(int l,int r) {
	if (prenum[r] - prenum[l-1] == (prexor[r] ^ prexor[l-1])) return true;
	return false;
}

void solve(int beg) {
	int l,r,ret;
	l = beg; r = n;
	while (l <= r) {
		int mid = (l+r)/2;
		if (check(beg,mid)) {
			l = mid+1;
			ret = mid;
		}else{
			r = mid-1;
		}
	}
	ans += ret-beg+1;
}

int main() {
	scanf("%lld",&n);
	for (int i = 1; i <= n; i++) {
		int num; scanf("%d",&num);
		prenum[i] = prenum[i-1]+num;
		prexor[i] = prexor[i-1]^num;
	}
	for (int i = 1; i <= n; i++) {
		solve(i);
	}
	printf("%lld\n",ans);
	return 0;
}