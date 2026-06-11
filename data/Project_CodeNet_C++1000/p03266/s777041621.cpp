#include<iostream>
#include<cassert>
#include<stdio.h>
#include<string>
#include<vector>
#include<map>
#include<tuple>
#include<algorithm>
#include<cmath>
#include<limits>
#include<set>
#include<deque>
#include<queue>
using namespace std;
#define int long  long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
typedef pair<int, int>P;
const int MOD = 1e9 + 7;
const int INF = 1e10;
const long double PI = (acos(-1));


signed main() {
	int N, K;
	cin >> N >> K;
	if (K & 1) {
		int n = N / K;
		int ans = n * n * n;
		cout << ans << endl;
	}
	else {
		int a = N / K;
		int b = N % K;
		int ans = 0;
		if (b >= K / 2)ans += (a + 1) * (a + 1) * (a + 1);
		else ans += a * a * a;
		ans += a * a * a;
		cout << ans << endl;
	}
}