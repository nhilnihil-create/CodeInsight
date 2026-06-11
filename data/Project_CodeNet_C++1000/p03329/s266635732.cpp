#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define maxs(a, b) a = max(a, b)
#define mins(a, b) a = min(a, b)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const ll linf = (1ll << 61);
const int inf = 1001001001;
const int mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> s(1, 6), t(1, 9);
	while (1) {
		int tmp = s.back();
		if (tmp * 6 <= n) s.push_back(tmp * 6);
		else break;
	}
	while (1) {
		int tmp = t.back();
		if (tmp * 9 <= n) t.push_back(tmp * 9);
		else break;
	}
	vector<int> dp(1000000, inf);
	dp[0] = 0;
	rep(i, n) {
		mins(dp[i + 1], dp[i] + 1);
		for (int j = 0; j < s.size(); ++j) {
			mins(dp[i + s[j]], dp[i] + 1);
		}
		for (int j = 0; j < t.size(); ++j) {
			mins(dp[i + t[j]], dp[i] + 1);
		}
	}
	cout << dp[n] << endl;
	return 0;
}
