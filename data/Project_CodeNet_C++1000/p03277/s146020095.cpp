#include <bits/stdc++.h>
using namespace std;

const int N = 6e5 + 5;
const int Base = 1e5 + 5;

#define int long long

int A[N], B[N], n, m, x, y;

#define lowbit(x) (x & (-x))

int S[N];

void add(int x, int v) {
	++ x;
	for(int i = x; i < N; i += lowbit(i)) S[i] += v;
}

int sum(int x) {
	++ x;
	int res = 0;
	for(int i = x; i; i -= lowbit(i)) res += S[i];
	return res;
}

int calc(int x) {
	int ans = 0;
	for(int i = 1; i <= n; ++ i) if(A[i] >= x) B[i] = 1;
	else B[i] = -1;
	//for(int i = Base - n - 1; i <= Base + n + 1; ++ i) S[i] = 0;
	memset(S, 0, sizeof(S));
	add(0 + Base, 1);
	for(int i = 1; i <= n; ++ i) {
		B[i] = B[i - 1] + B[i];
		//if(x == 30) cerr << B[i] << " " << sum(B[i] - 1 + Base) <<" " << sum(-1 + Base) <<  endl;
		ans += sum(B[i] + Base);
		add(B[i] + Base, 1);
	}
	return ans;
}

set <int> all;

main(void) {
	cin >> n;
	for(int i = 1; i <= n; ++ i) scanf("%lld", &A[i]), all.insert(A[i]);
	int tot = n * (n + 1) / 2;
	tot = tot - (tot / 2 + 1);
	//cerr << calc(30) << endl;
	int l = 0, r = 1e9, res = 0;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(calc(mid + 1) <= tot) {
			r = mid - 1;
			res = mid;
		}
		else l = mid + 1;
	}
	res = *(all.lower_bound(res));
	cout << res << endl;
}