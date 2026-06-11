#include <bits/stdc++.h>
#define ll long long
#define maxn 200005 /*rem*/
#define mod 998244353
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
set<int> r;
int lz = 0;
int a[maxn];
int main() {
	int n;
	ll ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	int res = 0;
	for (int i = n; i >= 1; i--) {
		lz++;
		if (!r.empty() && a[i] + lz < *(--r.end())) {
			cout << -1 << endl;
			return 0;
		}
		r.insert(a[i] + lz);
		if (r.find(lz) != r.end()) r.erase(lz);
		ans += r.size();
	}
	if (!r.empty()) ans = -1;
	cout << ans << endl;
	return 0;
}
