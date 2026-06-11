#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
#include<map>
#include<iomanip>
#include<queue>
#include<stack>
#include<time.h>
#define rep(i,n)for(int i=0;i<n;i++)
#define int long long
#define ggr getchar();getchar();return 0;
#define prique priority_queue
#define mod 1000000007
#define inf 1e15
#define key 1e9
using namespace std;
typedef pair<int, int>P;
void yes() { cout << "Yay!" << endl; }
void no() { cout << ":(" << endl; }
template<class T> inline void chmax(T& a, T b) {
	a = std::max(a, b);
}
template<class T> inline void chmin(T& a, T b) {
	a = std::min(a, b);
}
bool prime(int n) {
	int cnt = 0;
	for (int i = 1; i <= sqrt(n); i++) {
		if (n % i == 0)cnt++;
	}
	if (cnt != 1)return false;
	else return n != 1;
}
int gcd(int x, int y) {
	if (y == 0)return x;
	return gcd(y, x % y);
}
int lcm(int x, int y) {
	return x / gcd(x, y) * y;
}
int kai(int x, int y) {
	int res = 1;
	for (int i = x - y + 1; i <= x; i++) {
		res *= i; res %= mod;
	}
	return res;
}
int mod_pow(int x, int y, int m) {
	int res = 1;
	while (y) {
		if (y & 1) {
			res = res * x % m;
		}
		x = x * x % m;
		y >>= 1;
	}
	return res;
}
int comb(int x, int y) {
	if (y > x)return 0;
	return kai(x, y)* mod_pow(kai(y, y), mod - 2, mod) % mod;
}
struct edge { int to, cost; };
int n, k;
signed main() {
	cin >> n >> k;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (i <= k)continue;
		else if (n % i < k)ans += (i - k) * (n / i);
		else ans += (i - k) * (n / i) + (n % i - k + 1);
	}
	cout << min(ans, n * n) << endl;
	ggr
}