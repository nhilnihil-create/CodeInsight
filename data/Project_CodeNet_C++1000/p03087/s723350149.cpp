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
	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;
	vector<int> l(q), r(q);
	rep(i,q) {
		cin >> l[i] >> r[i];
	}
	vector<int> v(n);
	rep(i,n-1) if (s.substr(i, 2) == "AC") v[i+1]++;
	vector<int> sum(n + 1);
	rep(i,n) sum[i+1] = sum[i] + v[i];
	rep(i,q) {
		cout << sum[r[i]] - sum[l[i]] << endl;
	}
}

int main() {
	solve();
	return 0;
}