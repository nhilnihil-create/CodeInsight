#include <bits/stdc++.h>
using namespace std;
#define maxn 300010
#define ll long long
#define db double
#define vi vector<int>
#define pb push_back
#define mod 998244353
#define fi first
#define pi pair<int, int>
#define se second
#define mp make_pair
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
// head
int n;
ll a, b, k;
ll jc[maxn], bjc[maxn];
ll c(int a, int b) {
	return jc[a] * bjc[b] % mod * bjc[a - b] % mod;
}
int main() {
	cin >> n >> a >> b >> k;
	jc[0] = bjc[0] = 1;
	for (int i = 1; i < maxn; i++)
		jc[i] = jc[i - 1] * i % mod, 
		bjc[i] = ksm(jc[i], mod - 2);
	ll ans = 0;
	for (int i = 0; i <= n; i++) {
		ll ns = k - a * i;
		if (ns % b) continue;
		ns /= b;
		if (ns < 0 || ns > n) continue;
		ll nans = c(n, ns) * c(n, i);
		ans = (ans + nans) % mod;
	}
	cout << ans << endl;
	return 0;
}
