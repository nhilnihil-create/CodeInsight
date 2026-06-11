#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<algorithm>
#include<numeric>
#include<cmath>
#include<queue>
#include<stack>
#include<list>
#include<unordered_map>
#include<unordered_set>
#include<cctype>
#include<iomanip>
#include<limits>
#include<bitset>

using namespace std;
typedef long long int ll; typedef pair<int, int> P;
const ll mod = 1e9 + 7;
const int inf = 1e9 + 7;
const ll linf = 1LL << 60;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define REP(i,m,n) for(int i=(m);i<(int)n;i++)
#define all(a) (a).begin(),(a).end()
#define allg(a) (a).begin(),(a).end(),greater<>()
#define SUM(a) accumulate((a).begin(),(a).end(),0)
#define d10 std::setprecision(10)
#define d20 std::setprecision(20)
#define sz size()
using str = string;
const double PI = 3.14159265359;
ll gcd(ll a, ll b) { ll t; while (b != 0) { t = a % b; a = b; b = t; }return a; }
int gcd(int a, int b) { int t; while (b != 0) { t = a % b; a = b; b = t; }return a; }
ll recfact(ll start, ll n) {
	ll i;
	if (n <= 16) {
		ll r = start;
		for (i = start + 1; i < start + n; i++) r = r * i % mod;
		return r % mod;
	}
	i = n / 2;
	return recfact(start, i) % mod * recfact(start + i, n - i) % mod;
}
ll lcm(ll a, ll b) {
	return a * b / gcd(a, b);
}
ll fct(ll n) { return recfact(1, n); }
ll ncm(ll n, ll m) {
	if (n < m)return 0;
	ll x = (fct(n) % mod / (fct(m) * fct(n - m)) % mod) % mod;
	return x;
}
bool isincluded(char x, string str) {
	bool f = 0;
	for (size_t i = 0; i < str.size(); i++) {
		if (str.at(i) == x)f = 1;
	}
	return f;
}
int ctoi(char c) {
	if ('0' <= c && c <= '9') {
		return c - '0';
	}
	return 0;
}




int main(void) {
	str s; cin >> s;
	int n = s.sz;
	int tmp, ans = n;
	rep(i, n) {
		if (s[i] != s[i + 1]) {
			tmp = max(i + 1, n - 1 - i);
			ans = min(ans, tmp);
		}
	}
	cout << ans << endl;

	return 0;
}