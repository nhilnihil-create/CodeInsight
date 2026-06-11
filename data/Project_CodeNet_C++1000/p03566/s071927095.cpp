#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdlib>
#include <map>
#include <iomanip>
#include <set>
using namespace std;
#define pie 3.141592653589793238462643383279
#define int long long
#define mod 1000000007
#define INF 1145141919364364
#define all(vec) vec.begin(),vec.end()
#define P pair<int,int>
#define S second
#define F first
int gcd(int x, int y) {
	if (y == 0)return x;
	return gcd(y, x%y);
}
int lcm(int x, int y) {
	return x / gcd(x, y)*y;
}
bool prime(int x) {
	for (int i = 2; i <= sqrt(x); i++) {
		if (x%i == 0)return false;
	}
	return true;
}

int kai(int x) {
	if (x == 0)return 1;
	return kai(x - 1)*x%mod;
}

int mod_pow(int x, int y, int mood) {
	int res = 1;
	while (y > 0) {
		if (y & 1)res = res * x%mood;
		x = x * x%mood;
		y >>= 1;
	}
	return res;
}

int comb(int x, int y) {
	return kai(x)* mod_pow(kai(x - y), mod - 2, mod) % mod * mod_pow(kai(y), mod - 2, mod) % mod;
}

double f(double x, int l, int r, int v) {
	if (x < l)return v + (l - x);
	else if (r < x)return v + (x - r);
	else return v;
}

int n, t[100], v[100];
double cnt[4000010];
vector<P> vec;
double a, b, k, l;
double ans;

signed main() {
	cin >> n;
	vec.push_back({ 0,0 });
	for (int i = 0; i < n; i++)cin >> t[i];
	for (int i = 0; i < n; i++)cin >> v[i];
	for (int i = 0; i < n; i++) {
		vec.push_back({ vec[i].first + t[i],v[i] });
	}
	vec.push_back({ vec[n].first,0 });
	for (double i = 0; i <= vec[n].first; i += 0.5) {
		double coun = f(i, 0, 0, 0);
		for (int j = 0; j <= n; j++) {
			coun = min(coun, f(i, vec[j].first, vec[j + 1].first, vec[j + 1].second));
		}
		int c = i * 2.0;
		cnt[c] = coun;
	}
	a = 0;
	k = 0;
	l = 0;
	for (int i = 2; i <= vec[n].first * 2; i++) {
		if (cnt[i - 1] < cnt[i])b = 0;
		else if (cnt[i] < cnt[i - 1])b = 1;
		else b = 2;
		if (a != b) {
			ans += (k + cnt[i - 1]) / 2.0 * ((i - 1 - l) / 2.0);
			a = b;
			k = cnt[i - 1];
			l = i - 1;
		}
	}
	ans += (k + cnt[vec[n].first * 2]) / 2.0*(vec[n].first * 2 - l) / 2.0;
	printf("%.10f", ans);
}