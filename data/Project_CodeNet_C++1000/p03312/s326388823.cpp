#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
const int Maxn = 200005;
const ll Inf = 4000000000000000000ll;
 
int n;
ll sum[Maxn];
ll res = Inf;
 
void Get(int l, int r, ll &fir, ll &sec)
{
	ll res = Inf;
	int lef = l, rig = r - 1;
	while (lef <= rig) {
		int mid = lef + rig >> 1;
		ll a = sum[mid] - sum[l - 1];
		ll b = sum[r] - sum[mid];
		if (abs(a - b) < res) {
			res = abs(a - b);
			fir = a; sec = b;
		}
		if (a <= b) lef = mid + 1;
		else rig = mid - 1;
	}
}
 
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int a; scanf("%d", &a);
		sum[i] = a + sum[i - 1];
	}
	for (int i = 2; i <= n - 2; i++) {
		ll a, b; Get(1, i, a, b);
		ll c, d; Get(i + 1, n, c, d);
		ll cand = max(max(a, b), max(c, d)) - min(min(a, b), min(c, d));
		res = min(res, cand);
	}
	cout << res << endl;
	return 0;
}