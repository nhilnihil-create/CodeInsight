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
	int N;
	cin >> N;
	if (N == 0) {
		cout << 0;
		return 0;
	}
	vector<int>ans;
	while (N != 0) {
		if (N % 2) {
			ans.push_back(1);
			N--;
			N /= -2;
		}
		else {
			ans.push_back(0);
			N /= -2;
		}
	}
	rep(i, ans.size())cout << ans[ans.size() - 1 - i];
}