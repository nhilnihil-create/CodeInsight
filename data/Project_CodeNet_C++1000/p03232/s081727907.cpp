#include <stdio.h>
#include <iostream>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;
#define ll long long
const int N = 1e5+15;
const int mod = 1e9 + 7;
int add(int x, int y) {
	int ret = (x + y) % mod;
	if (ret < 0) {
		ret += mod;
	}
	return ret;
}
int mul(int x, int y) {
	return (ll)x*y%mod;
}
int mypow(int x, int c) {
	int ret = 1;
	while (c > 0) {
		if (c & 1) {
			ret = mul(ret, x);
		}
		x = mul(x, x);
		c /= 2;
	}
	return ret;
}
int fac[N], A[N], pre[N];
void solve() {
	int n;
	scanf("%d ", &n);
	fac[0] = 1;
	pre[0] = 0;
	for (int i = 1; i <= n; ++i) {
		scanf("%d ", &A[i]);
		pre[i] = add(pre[i-1], A[i]);
		fac[i] = mul(fac[i - 1], i);
		pre[i] = add(pre[i - 1], mypow(i, mod - 2));
	}
	int ret = 0;
	for (int i = 1; i <= n; ++i) {
		int tmp = pre[i];
		tmp = add(tmp, pre[n - i + 1]);
		tmp = add(tmp, -1);
		tmp = mul(tmp, A[i]);
		ret = add(ret, tmp);
	}
	ret = mul(ret, fac[n]);
	cout << ret << endl;
}

int main(){
	//freopen("input.txt", "r", stdin);
	solve();
}