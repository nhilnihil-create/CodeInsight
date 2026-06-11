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
const int INF = 1e10;
const long double PI = (acos(-1));


signed main() {
	int N;
	cin >> N;
	vector<int>a(N);
	double sum = 0;
	rep(i, N) {
		cin >> a[i];
		sum += a[i];
	}
	P mn = make_pair(INF, INF);
	rep(i, N) {
		P p = make_pair(abs(N * a[i] - sum), i);
		mn = min(mn, p);
	}
	cout << mn.second;
}