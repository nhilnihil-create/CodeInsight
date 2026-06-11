#include <bits/stdc++.h>
#define ll long long

using namespace std;

int lowbit(int x) { return (x & -x); }

const int N = 1e5 + 5;

int n;
ll k; 
int a[N], cnt[N << 1], pre[N << 1];

int pl(int x, int y) { return x > y ? -1 : 1; }

void update(int x) {
	while(x <= (N << 1)) {
		++cnt[x];
		x += lowbit(x);	
	}
}

int query(int x) {
	int ret = 0;
	while(x) {
		ret += cnt[x];
		x -= lowbit(x);
	}
	return ret;
}

bool check(int x) {
	memset(cnt, 0, sizeof cnt);
	memset(pre, 0, sizeof pre);
	for(int i = 1; i <= n; i++) pre[i] = pre[i - 1] + pl(a[i], x);
	for(int i = 0; i <= n; i++) pre[i] += n + 1;
	ll sum = 0;
	for(int i = 0; i <= n; i++) {
		sum += query(pre[i] - 1);
		update(pre[i]);
	}
	return (sum >= k);
}

int main() {
	cin >> n;
	k = 1ll * n * (n + 1) / 4 + 1;
	for(int i = 1; i <= n; i++) scanf("%d", a + i);
	int l = 1, r = 1e9;
	while(l < r) {
		int mid = (l + r) >> 1;
		if(check(mid)) r = mid;
		else l = mid + 1; 
	}
	cout << l << endl;
	return 0;
}