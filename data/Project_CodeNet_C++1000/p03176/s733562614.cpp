#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 2e5+5;

struct Bit {
	int bit[maxn] = {};
	int lowbit(int x) {
		return ((x)&(-x));
	}
	void upd(int x,int val) {
		for (int i = x; i < maxn; i += lowbit(i)) 
			bit[i] = max(bit[i], val);
	}
	int qry(int x) {
		int ret = 0;
		for (int i = x; i > 0; i -= lowbit(i))
			ret = max(ret, bit[i]);
		return ret;
	}
} bit;

int h[maxn], a[maxn];
int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> h[i];
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		int mx = bit.qry(h[i]-1) + a[i];
//		cout << mx << "\n";
		bit.upd(h[i], mx);
		
	}
	cout << bit.qry(n) << "\n";
}