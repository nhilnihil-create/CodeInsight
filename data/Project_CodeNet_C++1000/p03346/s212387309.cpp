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
int n;
int p[maxn], q[maxn], nx[maxn];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d", &p[i]), q[p[i]] = i;
	int ans = 0;
	for (int i = n; i >= 1; i--) {
		if (i == n) nx[i] = i;
		else {
			if (q[i + 1] > q[i]) nx[i] = nx[i + 1];
			else nx[i] = i;
		}
		ans = max(ans, nx[i] - i + 1);
	}
	cout << n - ans << endl;
	return 0;
}
