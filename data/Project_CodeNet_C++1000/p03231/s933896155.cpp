#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <cmath>

using namespace std;
#define PI 3.1415926535897932384626433832795
#define MOD (1000000007)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repc(i, s, n) for (int i = (s); i <= (n); i++)
#define rrep(i, n) for (int i = (n) - 1; i >= 0; i--)
#define rrepc(i, s, n) for (int i = (s); i >= (n); i--)
typedef long long ll;
typedef unsigned long long ull;

/*================================================
	GCD function
================================================*/
ll gcd(ll a, ll b) {
	if (a < b) return gcd(b, a);
	ll r;
	while ((r = a % b)) {
		a = b;
		b = r;
	}
	return b;
}

/*================================================
	LCM function
================================================*/
ll lcm(ll a, ll b) {
	return (a / (gcd(a, b))) * b;
}

int main()
{
	ll N, M, GCD, LCM, ans = -1;
	string S, T;
	bool ok = true;

	cin >> N >> M >> S >> T;
	GCD = gcd(N, M);
	LCM = lcm(N, M);

	for (ll i = 0; i < GCD; i++) {
		if (S[i * (N / GCD)] != T[i * (M / GCD)]) ok = false;
	}

	if (ok) ans = LCM;
	else ans = -1;

	cout << ans << endl;

	return 0;
}
