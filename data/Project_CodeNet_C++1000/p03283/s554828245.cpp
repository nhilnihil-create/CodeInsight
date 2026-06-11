#include <bits/stdc++.h>

#define M_PI       3.14159265358979323846   // pi

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> VI;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> t3;
typedef tuple<ll, ll, ll, ll> t4;
typedef tuple<ll, ll, ll, ll, ll> t5;

#define rep(a,n) for(ll a = 0;a < n;a++)
#define repi(a,b,n) for(ll a = b;a < n;a++)

using namespace std;

static const ll INF = 1e15;

template<typename T>
static inline void chmin(T & ref, const T  value) {
    if (ref > value) ref = value;
}

template<typename T>
static inline void chmax(T & ref, const T value) {
    if (ref < value) ref = value;
}

const ll mod = 1000000007;

int main() {
	ll n, m, q;
	cin >> n >> m >> q;
	vector <vector<ll>> grid(n + 1, vector<ll>(n + 1, 0));
	rep(i, m) {
		ll l, r;
		cin >> l >> r;
		grid[l][r]++;
	}
	vector <vector<ll>> sum(n + 2, vector<ll>(n + 2, 0));
	rep(i, n+1) {
		rep(j, n + 1) {
			sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + grid[i][j];
		}
	}
	vector<ll> ans;
	rep(i, q) {
		ll a, b;
		cin >> a >> b;
		auto v = sum[b+1][b+1] - sum[a][b+1] - sum[b+1][a] + sum[a][a];
		ans.push_back(v);
	}
	rep(i, q) {
		cout << ans[i] << endl;
	}
    return 0;
}

