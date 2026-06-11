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
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef pair<int, int>P;
const int MOD = 1e9 + 7;
//const int MOD = 998244353;
const int INF = 1e11;
const long double PI = (acos(-1));


signed main() {
	int H, W;
	cin >> H >> W;
	vector<vector<int>>a(H, vector<int>(W));
	rep(i, H)rep(j, W) {
		int A;
		cin >> A;
		a[i][j] = A % 2;
	}
	vector<P>ans;
	int f = 0;
	rep(i, H) {
		rep(j, W) {
			if (a[i][j] && j + 1 < W) {
				a[i][j]--;
				a[i][j + 1]++;
				a[i][j + 1] %= 2;
				ans.push_back({ i + 1,j + 1 });
				f++;
			}
		}
	}
	int s = 0;
	rep(i, H) {
		if (a[i][W - 1] && i + 1 < H) {
			a[i][W - 1]--;
			a[i + 1][W - 1]++;
			a[i + 1][W - 1] %= 2;
			ans.push_back({ i + 1,W });
			s++;
		}
	}
	cout << f + s << endl;
	rep(i, f)cout << ans[i].first << " " << ans[i].second << " " << ans[i].first << " " << ans[i].second + 1 << endl;
	rep(i, s)cout << ans[f + i].first << " " << ans[f + i].second << " " << ans[f + i].first + 1 << " " << ans[f + i].second << endl;
}