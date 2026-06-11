#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define REP(i, a, b) for(ll i = a; i <= b; i++)
#define out(x) cout << x << '\n'
#define all(a) a.begin(), a.end()
#define pb push_back
#define sz(x) ((int)(x).size())
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { ll g = gcd(a, b); return a / g * b; }
const int dx[4] = { 1, 0, -1,  0 };
const int dy[4] = { 0, 1,  0, -1 };
const int INF = (int)1e9;
const ll  inf = (ll)1e18;
const int mod = 1000000007;
const int MAX_N = 100010;

int manh(int x1, int x2, int y1, int y2) {
	return abs(x1 - x2) + abs(y1 - y2);
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll n, m;
	cin >> n >> m;

	ll sum = 0;
	sum += 1900LL * m + 100LL * (n - m);

	out(sum * (1LL << m));

	return 0;
}