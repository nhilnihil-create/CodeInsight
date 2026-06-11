#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i=0;i<n;i++)
#define REP(i, n) for(int i=1;i<=n;i++)
typedef long long ll;

const ll INF = 1LL << 60;
ll d[35][35];
ll C[3][35];

int main() {
	int n, c;
	cin >> n >> c;
	REP(i, c) REP(j, c) cin >> d[i][j];
	REP(i, n) {
		REP(j, n) {
			ll c;
			cin >> c;
			C[(i + j) % 3][c]++;
		}
	}
	
	ll ans = INF;
	REP(i, c) {
		REP(j, c) {
			REP(k, c) {
				ll dif = 0;
				if (i == j || j == k || k == i) continue;
				REP(l, c) {
					dif += d[l][i] * C[0][l];
				}
				REP(l, c) {
					dif += d[l][j] * C[1][l];
				}
				REP(l, c) {
					dif += d[l][k] * C[2][l];
				}
				ans = min(ans, dif);
			}
		}
	}
	
	cout << ans << endl;
	return 0;
}