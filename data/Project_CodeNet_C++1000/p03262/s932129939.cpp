#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std; using ll = long long;
using ull = unsigned long long; using P = pair<int, int>;
const int INF = 1e9; const int MOD = 1000000007;
const int dx[] = {-1,0,1,0}; const int dy[] = {0,-1,0,1};
//const int dx[] = {-1,-1,-1, 0, 0, 1, 1, 1}; const int dy[] = {-1, 0, 1,-1, 1,-1, 0, 1};
#define PI 3.14159265358979323846264338327950L //setprecision(15)
// 最大公約数(ユークリッドの互除法)
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
const int MAX_N = 200000;
int main() {
	int N, X; cin >> N >> X;
	int x[MAX_N];
	rep(i, N) cin >> x[i];
	int ans = max(X-x[0], x[0]-X);
	rep(i, N) {
		int tmp = max(X-x[i], x[i]-X);
		ans = gcd(ans, tmp);
	}
	cout << ans << endl;
}