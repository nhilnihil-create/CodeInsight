#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
//#include<bits/stdc++.h>
#define int long long
#define mod 998244353
#define for0(i, n) for(int i = 0; i < (n); i++)
#define for1(i, n) for(int i = 1; i <= (n);i++)
#define mp make_pair
#define all(x) x.begin(),x.end()
#define puts(x) cout << x << endl
using namespace std;
int input() {
	int r;
	cin >> r;
	//scanf("%lld", &r);
	return r;
}
int f1(int a, int p) {
	if (p == 1)return a;
	if (p % 2)return f1(a, p - 1) * a % mod;
	else return f1(a * a % mod, p / 2) % mod;
}
int c[345678], n, a, b, k, ans;
signed main() {
	cin >> n >> a >> b >> k;
	c[0] = 1;
	for1(i, n)c[i] = c[i - 1] * (n - i + 1) % mod * f1(i, mod - 2) % mod;
	for0(i, n + 1) {
		if (a * i > k)break;
		if (b * n + a * i < k)continue;
		if ((k - (a * i)) % b == 0) ans += c[i] * c[(k - a * i) / b] % mod;
		ans %= mod;
	}puts(ans);
}