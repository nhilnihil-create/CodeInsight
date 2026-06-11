#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using P   = pair<ll, ll>;
using mat = vector<vector<ll>>;

void IOS() { ios::sync_with_stdio(false), cin.tie(0); }

const ll INF = 1e16;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-10;

template <typename T> void dump(T x) { cout << x << endl; }
void dumpf(ld x, int t) { cout << setprecision(t) << fixed << x << endl; }
template <typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val) {
	fill((T *)array, (T *)(array + N), val);
}

inline ll mod(ll a, ll b) {
	if (a > 0) return a % b;
	if (a % b == 0) return 0;
	ll x = -a / b + 1;
	a += x * b;
	return a % b;
}

// ll dx[4] = {1, 0, -1, 0};
// ll dy[4] = {0, 1, 0, -1};

int main() {
	IOS();
	ll L;
	cin >> L;
	vector<bool> sosa;
	while (L > 2) {
		if (L % 2 == 0) {
			L /= 2;
			sosa.push_back(true);
		} else {
			L--;
			sosa.push_back(false);
		}
	}
	reverse(sosa.begin(), sosa.end());
	vector<P> g[21];
	g[1].push_back(P(2, 0));
	g[1].push_back(P(2, 1));
	// dump(sosa.size());
	ll now = 2, v = 2;
	ll l2 = 2;
	for (int i = 0; i < sosa.size(); i++) {
		if (sosa[i]) {
			for (int j = 1; j < now; j++) {
				for (int k = 0; k < g[j].size(); k++) {
					g[j][k].second *= 2;
				}
			}
			l2 *= 2;
			g[now].push_back(P(now + 1, 0));
			g[now].push_back(P(now + 1, 1));
			v += 2;
			now++;
		} else {
			g[1].push_back(P(now, l2));
			v++;
			l2++;
		}
		// dump(l2);
	}
	cout << now << " " << v << endl;
	for (int i = 1; i <= 20; i++) {
		for (int j = 0; j < g[i].size(); j++) {
			cout << i << " " << g[i][j].first << " " << g[i][j].second << endl;
		}
	}
}