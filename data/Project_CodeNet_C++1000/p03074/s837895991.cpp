#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define dunk(a) cout << (a) << "\n"
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int inf = 1001001001;
const int mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k; cin >> n >> k;
	string s;
	cin >> s;
	vector<P> res;
	int cnt = 1;
	rrep(i, n) {
		if (s[i] == s[i - 1]) cnt++;
		else {
			if (s[i] == '0') res.emplace_back(P(1, cnt));
			else res.emplace_back(P(0, cnt));
			cnt = 1;
		}
	}
	if (s.back() == '1') res.emplace_back(P(1, cnt));
	else res.emplace_back(P(0, cnt));
	int p = res.size();
	if (p <= 2 * k) {
		dunk(n);
		return 0;
	}
	int ans = 0;
	vector<ll> sum(n + 3 * k);
	sum[0] = 0;
	rep(i, res.size()) sum[i + 1] = sum[i] + res[i].second;
	ll j_ans = 0;
	rrep(i, res.size() + 1) {
		if (res[i - 1].first) {
			ll tmp = sum[min(p,i + 2 * k)] - sum[i - 1];
			j_ans = max(j_ans, tmp);
		}
		else {
			ll tmp = sum[min(p,i + 2 * k - 1)] - sum[i - 1];
			j_ans = max(j_ans, tmp);
		}
	}
	dunk(j_ans);
	return 0;
}
