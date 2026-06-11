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
	int x, y, z, k;
	cin >> x >> y >> z >> k;
	vector<ll> a(x), b(y), c(z);
	rep(i,x) cin >> a[i];
	rep(i,y) cin >> b[i];
	rep(i,z) cin >> c[i];
	vector<ll> v;
	rep(i,x) {
		rep(j,y) {
			v.push_back(a[i] + b[j]);
		}
	}
	sort(ALL(v), greater<>());
	int p = min((int)v.size(), k);
	vector<ll> ans;
	rep(i,p) {
		rep(j, z) {
			ans.push_back(v[i] + c[j]);
		}
	}
	sort(ALL(ans), greater<>());
	rep(i,k) cout << ans[i] << endl;
}

int main() {
	solve();
	return 0;
}