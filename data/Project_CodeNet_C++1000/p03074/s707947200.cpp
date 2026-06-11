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
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	vector<int> v;
	int flag = 1;
	int cnt = 0;
	rep(i,n) {
		if (flag == s[i] - '0') {
			cnt++;
		} else {
			v.push_back(cnt);
			cnt = 1;
			flag = 1 - flag;
		}
	}
	if (cnt) v.push_back(cnt);
	if (v.size() % 2 == 1) v.push_back(0);
	vector<int> sum(v.size() + 1);
	rep(i,v.size()) sum[i+1] = sum[i] + v[i];

	int ans = 0;
	for (int i = 0; i < (int) sum.size(); i += 2) {
		int t = sum[min(i + 2 * k + 1, (int) sum.size() - 1)] - sum[i];
		ans = max(ans, t);
	}
	cout << ans << endl;
}

int main() {
	solve();
	return 0;
}