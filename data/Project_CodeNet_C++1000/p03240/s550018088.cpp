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
	vector<int>x(N), y(N), h(N);
	rep(i, N)cin >> x[i] >> y[i] >> h[i];
	rep(i, N)rep(cx, 101)rep(cy, 101) {
		int H = abs(x[i] - cx) + abs(y[i] - cy) + h[i];
		if (H < 1)continue;
		bool isOK = true;
		for (int i = 1; i < N; i++) {
			int height = max(H - abs(x[i] - cx) - abs(y[i] - cy), 0ll);
			if (h[i] != height)isOK = false;
		}
		if (isOK) {
			cout << cx << " " << cy << " " << H << endl;
			return 0;
		}
	}
}