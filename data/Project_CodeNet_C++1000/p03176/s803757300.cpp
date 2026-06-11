#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

vector<long long> tree;
vector<int> lazy;
int n;
vector<long long> dp;
vector<int> beauty, height;

void update(int pos, int ind = 1, int l = 1, int r = n)
{
	if(l == r) {
		tree[ind] = dp[pos];
		return ;
	}
	int mid = (l+r)/2;
	if(pos <= mid) update(pos, 2*ind, l, mid);
	else update(pos, 2*ind+1, mid+1, r);
	tree[ind] = max(tree[2*ind], tree[2*ind+1]);
}

long long query(int ql, int qr, int ind = 1, int l = 1, int r = n)
{
	// printf("ql : %d qr : %d ind : %d l : %d r : %d\n", ql, qr, ind, l, r);
	if(ql > qr) return 0;
	if(l == r) return tree[ind];
	if(l == ql && r == qr) {
		return tree[ind];
	}
	int mid = (l+r)/2;
	return max(query(ql, min(qr, mid), 2*ind, l, mid), query(max(mid+1, ql), qr, 2*ind+1, mid+1, r));
}

int main() 
{
	scanf("%d", &n);
	beauty = vector<int>(n+1);
	height = vector<int>(n+1);
	dp = vector<long long>(n+1);
	tree = vector<long long>(100000000);
	for(int i = 0; i < n; i++) {
		scanf("%d", &height[i]);
	}
	for(int i = 0; i < n; i++) {
		scanf("%d", &beauty[i]);
	}
	long long ans = 0;
	for(int i = 0; i < n; i++) {
		long long max_ = query(0, height[i]);
		dp[height[i]] = max_ + beauty[i];
		update(height[i]);
		ans = max(ans, dp[height[i]]);
	}
	printf("%lld\n", ans);
 }