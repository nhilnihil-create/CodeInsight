#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define EPS 1e-9
#define mp make_pair
#define x first
#define y second
const double PI = acos(-1);

typedef pair<int, int> pii;
const int N = 200010;
const ll oo = 5e18;

int n;
ll X, x[N], f[N], pre[N];

int main() {
	cin >> n >> X;
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &x[i]);
		pre[i] = x[i] + pre[i - 1];
	}
	f[0] = f[1] = 5;
	for (int i = 2 ; i <= n ; ++i)
		f[i] = f[i - 1] + 2;
	ll res = oo;
	double mx = oo;
	for (int k = 1; k <= n; ++k) {
		int cur = n, idx = 0;
		ll fn = X * (n + k);
		long double me = X * (n + k);
		while (cur >= 1) {
			ll sum = pre[cur] - pre[max(0, cur - k)];
			me += sum * f[idx];
			if(me > oo)break;
			fn += sum * f[idx++];
			cur -= k;
		}
		if(me <= mx)res = min(res,fn);
	}
	cout << res << endl;
	return 0;
}