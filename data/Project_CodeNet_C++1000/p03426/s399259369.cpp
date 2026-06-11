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


vector<vector<int>>A;
int H, W, D;


P find(int n) {
	rep(i, H)rep(j, W) {
		if (A[i][j] == n) {
			return { i,j };
		}
	}
}


signed main() {
	cin >> H >> W >> D;
	A.resize(H);
	rep(i, H)A[i].resize(W);
	rep(i, H)rep(j, W)cin >> A[i][j];
	vector<int>d(H * W + 1);
	P now, next;
	for (int i = 1; i <= D; i++) {
		for (int j = i; j <= H * W; j += D) {
			if (j == i) {
				d[j] = 0;
				now = find(j);
			}
			else {
				next = find(j);
				d[j] = d[j - D] + abs(next.first - now.first) + abs(next.second - now.second);
				now = next;
			}
		}
	}

	int Q;
	cin >> Q;
	vector<int>ans(Q);
	rep(i, Q) {
		int L, R;
		cin >> L >> R;
		ans[i] = d[R] - d[L];
	}
	rep(i, Q)cout << ans[i] << endl;
}