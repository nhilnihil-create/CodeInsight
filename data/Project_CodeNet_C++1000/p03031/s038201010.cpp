#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MAX = 100000;
const int INF = 1e9;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};
#define PI 3.14159265358979323846264338327950L
#define MOD 1000000007
//setprecision(15)
int beki(int n, int e) {
	int d = n;
	for (int i = 1; i < e; i++) {
		n = n * d;
	}
	return n;
}

int main() {
	int N, M; cin >> N >> M;
	int v[10][10]; int k[10];
	rep(i, M) {
		cin >> k[i];
		rep(j, k[i]) {
			cin >> v[i][j]; v[i][j]--;
		}
	}
	int p[10]; rep(i, M) cin >> p[i];
	int be = beki(2, N);
	int ans = 0;
	for (int i = 0; i < be; i++) {
		for (int j = 0; j < M; j++) {
			int cnt = 0;
			for (int s = 0; s < k[j]; s++) {
				if (i & (1 << v[j][s])) cnt++;
			}
			if (cnt % 2 != p[j]) break;
			if (j == M - 1) ans++;
		}
	}
	cout << ans << endl;
}