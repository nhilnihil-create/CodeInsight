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
#include<stack>
using namespace std;
#define int long long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define dup(x,y) (((x)+(y)-1)/(y))
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef pair<int, int>P;
const int MOD = 1e9 + 7;
//const int MOD = 998244353;
const int INF = 1e18;
const long double PI = (acos(-1));


signed main() {
	int N;
	cin >> N;
	vector<int>A(N), B(N);
	rep(i, N)cin >> A[i];
	rep(i, N)B[i] = A[i];
	rep(i, N)B[i] -= i + 1;
	sort(B.begin(), B.end());
	if (N & 1) {
		int b = B[N / 2];
		int ans = 0;
		rep(i, N)ans += abs(A[i] - (i + 1 + b));
		cout << ans << endl;
	}
	else {
		int b;
		b = B[N / 2];
		int ans1 = 0;
		rep(i, N)ans1 += abs(A[i] - (i + 1 + b));

		b = B[N / 2 - 1];
		int ans2 = 0;
		rep(i, N)ans2 += abs(A[i] - (i + 1 + b));
		int ans = min(ans1, ans2);
		cout << ans << endl;
	}
}