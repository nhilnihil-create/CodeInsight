#include <bits/stdc++.h>
using namespace std;

const long long INF = 0x3f3f3f3f3f3f3f3f;

long long dp[5010], ndp[5010];
int a[5010], pos[5010];

void chmin(long long &a, long long b){a = a < b ? a : b;}

struct Segment_tree{
	long long minj[20010], lazy[20010];
	void pushup(int now){
		minj[now] = min(minj[now << 1], minj[now << 1 | 1]);
	}
	void pushdown(int now){
		if (lazy[now] == INF) return ;
		long long v = lazy[now]; lazy[now] = INF;
		chmin(minj[now << 1], v);
		chmin(lazy[now << 1], v);
		chmin(minj[now << 1 | 1], v);
		chmin(lazy[now << 1 | 1], v);
	}
	void Build(int now, int l, int r){
		memset(minj, 0x3f, sizeof(minj));
		memset(lazy, 0x3f, sizeof(lazy));
	}
	void Update(int now, int l, int r, int L, int R, long long x){
		if (l == L && r == R){
			chmin(minj[now], x);
			chmin(lazy[now], x);
			return ;
		}
		pushdown(now);
		int mid = l + r >> 1;
		if (R <= mid) Update(now << 1, l, mid, L, R, x);
		else if (L > mid) Update(now << 1 | 1, mid + 1, r, L, R, x);
		else Update(now << 1, l, mid, L, mid, x), Update(now << 1 | 1, mid + 1, r, mid + 1, R, x);
		pushup(now);
	}
	void get_dp(int now, int l, int r){
		if (l == r){
			dp[l] = minj[now];
			return ;
		}
		pushdown(now);
		int mid = l + r >> 1;
		get_dp(now << 1, l, mid), get_dp(now << 1 | 1, mid + 1, r);
	}
}seg;

int main(){
	int n, A, B;
	scanf("%d%d%d", &n, &A, &B);
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		pos[a[i]] = i + 1;
	}
	memset(dp, 0x3f, sizeof(dp));
	dp[0] = 0;
	for (register int i = 1; i <= n; i++){
		int x = pos[i];
		long long minj = INF;
		for (register int j = 0; j <= n; j++){
			minj = min(minj, dp[j]);
			dp[j] = minj + (j < x ? B : j > x ? A : 0);
		}
	}
	long long ans = INF;
	for (int i = 0; i <= n; i++){
		chmin(ans, dp[i]);
	}
	printf("%lld\n", ans);
	return 0;
}
