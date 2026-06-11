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

void solve() {
	ll n;
	cin >> n;
	vector<ll> v(5);
	rep(i,5) cin >> v[i];
	ll mn = v[0];
	rep(i,5) mn = min(v[i], mn);
	if (mn == n) {
		cout << 5 << endl;
		return;
	}
	cout << (n + mn - 1) / mn + 4ll << endl;
}

int main() {
	solve();
	return 0;
}