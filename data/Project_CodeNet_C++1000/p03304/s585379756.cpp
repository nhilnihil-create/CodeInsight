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
#define double long double
using namespace std;
typedef pair<int, int>P;
void pyes() { cout << "Yay!" << endl; }
void pno() { cout << ":(" << endl; }
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
signed main() {
	double n, m, d;
	cin >> n >> m >> d;
	if (d == 0)cout << setprecision(10) << (m - 1) / n << endl;
	else cout << setprecision(10) << (n - d) * 2 / (n * n) * (m - 1) << endl;
	ggr
}



