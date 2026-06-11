#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std; using ll = long long;
using ull = unsigned long long; using P = pair<int, int>;
const int INF = 1e9; const int MOD = 1000000007;
const int dx[] = {-1,0,1,0}; const int dy[] = {0,-1,0,1};
//const int dx[] = {-1,-1,-1, 0, 0, 1, 1, 1}; const int dy[] = {-1, 0, 1,-1, 1,-1, 0, 1};
#define PI 3.14159265358979323846264338327950L //setprecision(15)

int main() {
	int N, M, X; cin >> N >> M >> X;
	vector<int> v(N+1);
	rep(i, M) {
		int a; cin >> a;
		v[a] = 1;
	}
	int ans = INF;
	int tmp = 0;
	for (int i = X; i <= N+1; i++) {
		if (v[i] == 1) tmp++;
	}
	ans = min(ans, tmp);
	tmp = 0;
	for (int i = X; i >= 0; i--) {
		if (v[i] == 1) tmp++;
	}
	ans = min(ans, tmp);
	cout << ans << endl;
}