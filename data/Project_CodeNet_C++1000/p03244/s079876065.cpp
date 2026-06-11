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

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(10);
	/*------------------------------*/

	int n;
	cin >> n;
	vector<int> v(n);
	rep(i, n) cin >> v[i];

	map<int, int> odd, even;
	rep(i, n) {
		if (i % 2 == 0) {
			odd[v[i]]++;
		}
		else {
			even[v[i]]++;
		}
	}

	int omax1 = 0;
	int onum1 = 0;
	for (auto o : odd) {
		if(omax1 < o.second) {
			omax1 = o.second;
			onum1 = o.first;
		}
	}

	int omax2 = 0;
	int onum2 = 0;
	for (auto o : odd) {
		if (omax2 < o.second && o.first != onum1) {
			omax2 = o.second;
			onum2 = o.first;
		}
	}

	int emax1 = 0;
	int enum1 = 0;
	for (auto e : even) {
		if (emax1 < e.second) {
			emax1 = e.second;
			enum1 = e.first;
		}
	}

	int emax2 = 0;
	int enum2 = 0;
	for (auto e : even) {
		if (emax2 < e.second && e.first != enum1) {
			emax2 = e.second;
			enum2 = e.first;
		}
	}

	if (onum1 == enum1) {
		cout << min(n - emax1 - omax2, n - emax2 - omax1) << endl;
	}
	else {
		cout << n - emax1 - omax1 << endl;
	}

	return 0;
}