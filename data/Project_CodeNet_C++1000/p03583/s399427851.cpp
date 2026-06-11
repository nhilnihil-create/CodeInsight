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
	int N;
	cin >> N;
	for (int h = 1; h <= 3500; h++) {
		for (int n = 1; n <= 3500; n++) {
			int a = 4 * h * n - N * n - N * h;
			if (a == 0)continue;
			int b = N * h * n;
			if (b % a == 0) {
				int w = b / a;
				if (w <= 0)continue;
				cout << h << " " << n << " " << w << endl;
				return 0;
			}
		}
	}
}