#include<algorithm>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
ll a[200010],n;
ll ma(ll q, ll w, ll e, ll r) {
	return max(max(q, w), max(e, r));
}
ll mi(ll q, ll w, ll e, ll r) {
	return min(min(q, w), min(e, r));
}
int main()
{
	ll dap = 999999999999999;
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		a[i] += a[i - 1];
	}
	for (int i = 2; i <= n-2; i++) {
		ll ch = a[i];
		ll ch1 = a[n] - a[i];
		ll q, w, e, r,q1,w1,e1,r1;
		int t = lower_bound(a, a + n + 1, ch/2) - a;
		q = a[t];
		w = ch - q;
		t--;
		q1 = a[t];
		w1 = ch - q1;
		t = lower_bound(a, a + n + 1, ch + ch1 / 2) - a;
		e = a[t] - ch;
		r = ch1 - e;
		t--;
		e1 = a[t] - ch;
		r1 = ch1 - e1;
		dap = min(dap, ma(q, w, e, r) - mi(q, w, e, r));
		dap = min(dap, ma(q, w, e1, r1) - mi(q, w, e1, r1));
		dap = min(dap, ma(q1, w1, e, r) - mi(q1, w1, e, r));
		dap = min(dap, ma(q1, w1, e1, r1) - mi(q1, w1, e1, r1));
	}
	printf("%lld\n", dap);
}