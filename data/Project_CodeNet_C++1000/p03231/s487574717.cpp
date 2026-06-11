#include "bits/stdc++.h"
#include <set>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define RFOR(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep1(i, n) for (int i = 1; i < (n); i++)
#define rrep(i, n) for (int i = (n)-1; i >= 0; i--)
#define all(i) (i).begin(), (i).end()
#define rall(i) (i).begin(), (i).end(), greater<int>()
#define int long long
#define elif else if
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define fst first
#define sec second
#define mod 1000000007
#define INF 10e10
template <typename T>

void print(T x)
{
	std::cout << x << " ";
}
template <typename T>

void println(T x)
{
	std::cout << x << "\n";
}

int gcd(int a, int b) {
	if (a%b == 0)return b;
	else return gcd(b, a%b);
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

signed main(void) {
	int n, m;
	cin >> n >> m;
	string s, t;
	cin >> s >> t;
	int xsize = lcm(n, m);
	int a = xsize / n;
	int b = xsize / m;
	for (int i = 0; i*a < xsize; i++) {
		if (i*a%b == 0) {
			if (s[i] != t[i*a / b]) {
				print("-1");
				return 0;
			}
		}
	}
	print(xsize);
}