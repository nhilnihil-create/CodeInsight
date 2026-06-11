#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin (),(x).end()
#define sqrt(x) sqrt(abs(x))
#define re return
#define sz(x) ((int)(x).size ())
#define prev PREV
#define next NEXT

using ll = long long;
using ii = pair<int, int>;
using ld = long double;
using D = double;
using vi = vector<int>;
using vii = vector<ii>;
using vvi = vector<vi>;
using vs = vector<string>;

template<typename T> T abs (T x) { re x < 0 ? -x : x; }
template<typename T> T sgn (T x) { re x < 0 ? -1 : (x > 0 ? 1 : 0); }
template<typename T> T sqr (T x) { re x * x; }
template<typename T> T gcd (T a, T b) { re a ? gcd (b % a, a) : b; }

const int N = 200010;

int n;
int m;
char h[N];
int w[N];
int cnt[N][2];
vi v[N];
int was[N];
int q[N];

int main () {
	scanf ("%d%d", &n, &m);
	scanf (" %s", h);
	for (int i = 0; i < n; i++) w[i] = h[i] - 'A';
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf ("%d%d", &a, &b); a--; b--;
		v[a].pb (b);
		v[b].pb (a);
		cnt[a][w[b]]++;
		cnt[b][w[a]]++;
	}
	int l = 0, r = 0;
	for (int i = 0; i < n; i++)
		if (cnt[i][0] == 0 || cnt[i][1] == 0) {
			q[r++] = i;
			was[i] = 1;
		}
	while (l < r) {
		int x = q[l++];
		for (int i = 0; i < sz (v[x]); i++) {
			int y = v[x][i];
			if (!was[y]) {
				cnt[y][w[x]]--;
				if (cnt[y][w[x]] == 0) {
					was[y] = 1;
					q[r++] = y;
				}
			}
		}
	}
	if (r < n) printf ("Yes\n"); else printf ("No\n");
	return 0;
}