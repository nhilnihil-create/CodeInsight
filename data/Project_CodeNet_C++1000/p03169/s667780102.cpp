#pragma GCC optimize ("Ofast")
#include "bits/stdc++.h"
	
#define PI 3.141592653589793
#define FAST ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
// Use for file I/O;
#define FIN string _fname = "paintbarn"; \
			string _is = _fname + ".in", _os = _fname + ".out"; \
			freopen(_is.c_str(), "r", stdin); \
			freopen(_os.c_str(), "w", stdout);

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;

using namespace std;

const ll INF = 1e9 + 10;
const ll INF2 = 3e18 + 10;
const int MOD = 1e9 + 7;
const ld EPS = 1e-4;

const int LOGN = 19;
const int MAXN = 305;


int cnt[4];
ld p[MAXN][MAXN][MAXN], ev[MAXN][MAXN][MAXN];


int main() {
	FAST;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		cnt[a]++;
	}

	p[cnt[1]][cnt[2]][cnt[3]] = 1;
	for (int c = n; c >= 0; c--) {
		for (int b = n; b >= 0; b--) {
			for (int a = n; a >= 0; a--) {
				if (a + b + c > n) continue;
				if (a + b + c == 0) continue;
					
				ld p_waste = (ld) (n - a - b - c) / n;
				ld ev_waste = p_waste / (1.0L - p_waste);
				ev[a][b][c] += ev_waste * p[a][b][c];

				if (a) {
					ld pp = (ld) a / (a + b + c);
					p[a - 1][b][c] += p[a][b][c] * pp;		
					ev[a - 1][b][c] += ev[a][b][c] * pp;		
				}
				if (b) {
					ld pp = (ld) b / (a + b + c);
					p[a + 1][b - 1][c] += p[a][b][c] * pp;	
					ev[a + 1][b - 1][c] += ev[a][b][c] * pp;	
				}
				if (c) {
					ld pp = (ld) c / (a + b + c);
					p[a][b + 1][c - 1] += p[a][b][c] * pp;
					ev[a][b + 1][c - 1] += ev[a][b][c] * pp;
				}
			}
		}
	}

	cout << setprecision(17) << fixed << ev[0][0][0] + cnt[1] + 2 * cnt[2] + 3 * cnt[3];
}