#define _USE_MATH_DEFINES
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll MOD = 1e9 + 7;
const ll LINF = 1e18;
#define y0 y3487465
#define y1 y8687969
#define j0 j1347829
#define j1 j234892
#define next asdnext
#define prev asdprev
#define MP make_pair
#define F first
#define S second
#define PB push_back
#define dump(x)  cout << #x << " = " << (x) << endl;	//debug
#define SZ(x) ((ll)(x).size())
#define FOR(i, a, b) for (ll i = (a); i <= (b); i++)
#define RFOR(i, a, b) for (ll i = (a); i >= (b); i--)
#define ps(s) cout << #s << endl;
#define pv(v) cout << (v) << endl;
#define pvd(v) cout << setprecision(16) << (v) << endl;
#define ALL(a)  (a).begin(),(a).end()
#define RANGE(a, start_index, num)  (a).begin()+(start_index),(a).begin()+(num)

int n, a, b, c;
int L[8] = {};
int abc[8] = {};
int res = INF;

void dfs(int cnt, int tp) {
	abc[cnt] = tp;
	if (cnt == n - 1) {
		int la = 0, lb = 0, lc = 0;
		int na = 0, nb = 0, nc = 0;
		FOR(i, 0, n - 1) {
			if (abc[i] == 1) {
				la += L[i];
				na++;
			}
			if (abc[i] == 2) {
				lb += L[i];
				nb++;
			}
			if (abc[i] == 3) {
				lc += L[i];
				nc++;
			}
		}
		if (na == 0 || nb == 0 || nc == 0) {
			return;
		}
		int tmp = abs(a - la) + abs(b - lb) + abs(c - lc);
		if (na >= 2) tmp += (na - 1) * 10;
		if (nb >= 2) tmp += (nb - 1) * 10;
		if (nc >= 2) tmp += (nc - 1) * 10;
		res = min(res, tmp);
	}
	else {
		FOR(i, 0, 3) {
			dfs(cnt + 1, i);
		}
	}
}

int main() {
	cin >> n >> a >> b >> c;
	FOR(i, 0, n-1) {
		cin >> L[i];
	}
	FOR(i, 0, 3) {
		dfs(0, i);
	}
	pv(res)
	return 0;
}