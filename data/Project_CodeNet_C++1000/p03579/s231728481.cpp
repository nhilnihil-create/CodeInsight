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
const long double PI = acos(-1);

int N, M;
vector<int> E[100010];
int C[100010];
int num[100010];

void dfs(int cur, int col) {
	if (C[cur] != -1) {
		if (C[cur] != col) {
			//完全グラフからM引いた値
			cout << 1LL * N * (N - 1LL) / 2 - M << endl;
			exit(0);
		}
	}
	else {
		C[cur] = col;
		num[col]++;
		for (auto e : E[cur]) {
			dfs(e, col ^ 1);
		}
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(10);
	/*------------------------------*/

	cin >> N >> M;

	rep(i, M) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		E[x].push_back(y);
		E[y].push_back(x);
	}

	for (int i = 0; i < 100010; i++) {
		C[i] = -1;
	}

	dfs(0, 0);

	cout << 1LL * num[0] * num[1] - M << endl;

	return 0;
}