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
const int INF = 1e10;
const long double PI = (acos(-1));


signed main() {
	int N, K;
	string S;
	cin >> N >> K >> S;
	vector<int>v;
	if (S[0] == '0')v.push_back(0);
	char now;
	int cnt = 1;
	rep(i, N - 1) {
		if (S[i] == S[i + 1])cnt++;
		else {
			v.push_back(cnt);
			cnt = 1;
		}
	}
	v.push_back(cnt);
	if (S[N - 1] == '0')v.push_back(0);
	vector<int>d(v.size() + 1, 0);
	rep(i, v.size())d[i + 1] = d[i] + v[i];
	int left = 1;
	int right = 2 * K + 1;
	int ans = -INF;
	while (right <= d.size()) {
		ans = max(ans, d[right] - d[left - 1]);
		left += 2;
		right += 2;
	}
	if (ans == -INF)ans = N;
	cout << ans << endl;
}