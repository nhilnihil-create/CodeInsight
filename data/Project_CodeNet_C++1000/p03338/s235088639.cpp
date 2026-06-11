#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std; using ll = long long;
using ull = unsigned long long; using P = pair<int, int>;
const int INF = 1e9; const int MOD = 1000000007;
const int dx[] = {-1,0,1,0}; const int dy[] = {0,-1,0,1};
//const int dx[] = {-1,-1,-1, 0, 0, 1, 1, 1}; const int dy[] = {-1, 0, 1,-1, 1,-1, 0, 1};
#define PI 3.14159265358979323846264338327950L //setprecision(15)
int a[100][26];
int b[100][26];
int main() {
	int N; cin >> N;
	string s; cin >> s;
	for (int i = 0; i < N - 1; i++) {
		int tmp = s[i] - 'a';
		for (int j = i; j < 100; j++) a[j][tmp] = 1;
	}
	for (int i = 0; i < N - 1; i++) {
		int tmp = s[N-1-i] - 'a';
		for (int j = i; j < 100; j++) b[j][tmp] = 1;
	}
	int ans = 0;
	for (int i = 0; i < N - 1; i++) {
		int cnt = 0;
		rep(j, 26) {
			if (a[i][j] == 1 && b[N-2-i][j] == 1) {
				cnt++;
			}
		}
		ans = max(ans, cnt);
	}
	cout << ans << endl;
}