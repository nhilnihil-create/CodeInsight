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

int minf[MAX + 1];
int s[MAX + 1];
// エラトステネスの篩
void sieve() {
	memset(minf, -1, sizeof(minf));
	for (int i = 2; i <= MAX; i++) {
		if (minf[i] != -1) continue;
		minf[i] = i;
		for (int j = i * 2; j <= MAX; j += i) {
			minf[j] = i;
		}
	}
}

void make_tbl_2017() {
	int cnt = 0;
	for (int i = 3; i <= MAX; i++) {
		s[i] = cnt;
		if (minf[i] == i && minf[(i+1)/2] == (i+1)/2) cnt++;
	}
}

int main() {
	sieve();
	make_tbl_2017();
	int Q; cin >> Q;
	int ans[100000];
	rep(i, Q) {
		int l, r; cin >> l >> r;
		if (minf[r] == r && minf[(r+1)/2] == (r+1)/2) {
			ans[i] = s[r] - s[l] + 1;
		} else {
			ans[i] = s[r] - s[l];
		}
	}
	rep(i, Q) {
		cout << ans[i] << endl;
	}
}