#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define REP(i, a, b) for(ll i = a; i <= b; i++)
#define out(x) std::cout << x << '\n'
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define sz(x) ((int)(x).size())
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { ll g = gcd(a, b); return a / g * b; }
const int dx[4] = { 1, 0, -1,  0 };
const int dy[4] = { 0, 1,  0, -1 };
const int INF = INT_MAX / 2;
const ll  inf = LLONG_MAX / 2;
const int mod = 1000000007;
const int MAX_N = 101010;
const double PI = acos(-1);

double distance(double a1, double a2, double b1, double b2) {
	return sqrt((a1 - b1) * (a1 - b1) + (a2 - b2) * (a2 - b2));
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(10);
	/*------------------------------*/

	int h, w;
	cin >> h >> w;

	vector<vector<int>> a(h, vector<int>(w));
	rep(i, h) {
		rep(j, w) {
			cin >> a[i][j];
		}
	}

	vector<pair<P, P>> ans;
	for (int i = 0; i < h; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < w; j++) {
				if (a[i][j] % 2 == 1) {
					a[i][j]--;
					if (j == w - 1) {
						if (i + 1 < h) {
							a[i + 1][j]++;
							ans.push_back(make_pair(P(i, j), P(i + 1, j)));
						}
					}
					else {
						a[i][j + 1]++;
						ans.push_back(make_pair(P(i, j), P(i, j + 1)));
					}
				}
			}
		}
		else {
			for (int j = w - 1; j >= 0; j--) {
				if (a[i][j] % 2 == 1) {
					a[i][j]--;
					if (j == 0) {
						if (i + 1 < h) {
							a[i + 1][j]++;
							ans.push_back(make_pair(P(i, j), P(i + 1, j)));
						}
					}
					else {
						a[i][j - 1]++;
						ans.push_back(make_pair(P(i, j), P(i, j - 1)));
					}
				}
			}
		}
	}

	cout << sz(ans) << endl;
	for (auto p : ans) {
		cout << p.first.first + 1 << " " << p.first.second + 1 << " "
			<< p.second.first + 1 << " " << p.second.second + 1 << endl;
	}

	return 0;
}