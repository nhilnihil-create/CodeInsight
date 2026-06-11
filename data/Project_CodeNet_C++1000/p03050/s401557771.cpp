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
	int N;
	cin >> N;
	int ans = 0;
	for (int i = 1; i * i <= N; i++) {
		if (N % i == 0) {
			int n = N / i;
			if (i < n - 1)ans += n - 1;
		}
	}
	cout << ans << endl;
}