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
	vector<ll> a(n), b(n);
	rep(i,n) cin >> a[i];
	rep(i,n) cin >> b[i];
	vector<ll> mns;
	vector<ll> pls;
	rep(i,n) {
		int x = a[i] - b[i];
		if (x < 0) mns.push_back(x);
		else if (x > 0) pls.push_back(x);
	}
	ll p = 0;
	rep(i,mns.size()) p += mns[i];
	sort(ALL(pls), greater<>());
	vector<ll> sum(pls.size()+1);
	rep(i,pls.size()) sum[i+1] = sum[i] + pls[i];
	p = abs(p);
	if (p > sum[pls.size()]) {
		cout << -1 << endl;
		return;
	}
	if (mns.size() == 0) {
		cout << 0 << endl;
		return;
	}
	int ans = mns.size() + upper_bound(ALL(sum), p) - sum.begin(); 
	cout << ans << endl;

}

int main() {
	solve();
	return 0;
}