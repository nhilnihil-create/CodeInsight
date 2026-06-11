#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define ls (idx << 1)
#define rs (idx << 1 | 1)
#define mem(x, a) memset(x, a, sizeof(x))
#define AC ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;

const int maxn = 2e5 + 50;
int seg[maxn*4], a[maxn], h[maxn];

void modify(int pos, int val, int l, int r, int idx){
	if(l == r){
		seg[idx] = val;
		return;
	}
	int mid = (l + r) >> 1;
	if(pos <= mid) modify(pos, val, l, mid, ls);
	else modify(pos, val, mid + 1, r, rs);
	seg[idx] = max(seg[ls], seg[rs]);
}

int query(int A, int B, int l, int r, int idx){
	if(A <= l && B >= r) return seg[idx];
	int mid = (l + r) >> 1;
	int ans = 0;
	if(A <= mid) ans = max(ans, query(A, B, l, mid, ls));
	if(B > mid) ans = max(ans, query(A, B, mid + 1, r, rs));
	return ans;
}

main(){
	AC;
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++) cin >> h[i];
	for(int i = 1; i <= n; i ++) cin >> a[i];
	for(int i = 1; i <= n; i ++){
		modify(h[i], query(1, h[i], 1, n, 1) + a[i], 1, n, 1);
	}
	cout << query(1, n, 1, n, 1) << "\n";
}