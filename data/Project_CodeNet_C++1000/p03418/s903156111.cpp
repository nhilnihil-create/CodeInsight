#include<iostream>
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
//const int MOD = 998244353;
const int INF = 1e10;
const long double PI = (acos(-1));


signed main() {
	int N, K;
	cin >> N >> K;
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		int a = N / i;
		ans += a * max(0ll, i - 1 - K + 1);
		int b = N % i;
		if (K == 0)ans += b;
		else ans += max(0ll, b - K + 1);
	}
	cout << ans << endl;
}