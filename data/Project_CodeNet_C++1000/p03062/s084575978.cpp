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
	int n;
	cin >> n;
	vector<ll> v(n);
	rep(i,n) cin >> v[i];
	ll sum = 0;
	ll mn = INF;
	int c = 0;
	rep(i,n) {
		ll a = v[i];
		mn = min(mn, abs(a));
		sum += abs(a);
		if (a < 0) c++;
	}
	if (c % 2 == 0) {
		cout << sum << endl;
	} else {
		cout << sum - 2 * mn << endl;
	}
}

int main() {
	solve();
	return 0;
}