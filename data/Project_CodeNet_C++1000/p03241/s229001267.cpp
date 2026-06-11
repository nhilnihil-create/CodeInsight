#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

ll solve(ll n, ll m) {
	ll mx = m / n;
	vector<ll> v;
	for (ll i = 1; i * i <= m; i++) {
		if (m % i != 0) continue;
		if (i <= mx) v.push_back(i);
		if (m / i <= mx) v.push_back(m / i);
	}
	sort(ALL(v));
	return v[v.size() - 1];
}

int main() {
	ll n, m;
	cin >> n >> m;
	cout << solve(n, m) << endl;
}