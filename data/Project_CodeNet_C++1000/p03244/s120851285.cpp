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
	vector<int> cnt1(100005), cnt2(100005);
	rep(i, n) {
		int a;
		cin >> a;
		if (i % 2 == 1) cnt2[a]++;
		else cnt1[a]++;
	}
	vector<int> p(100005);
	iota(p.begin(), p.end(), 0);
	vector<int> p_(100005);
	iota(p_.begin(), p_.end(), 0);
	sort(p.begin(), p.end(), [&](const auto& x, const auto& y) {
		return cnt1[x] > cnt1[y];
		});
	sort(p_.begin(), p_.end(), [&](const auto& x, const auto& y) {
		return cnt2[x] > cnt2[y];
		});
	if (p.front() == p_.front()) {
		int ans = n - cnt1[p[0]];
		if (cnt1[p[1]] >= cnt2[p_[1]]) ans -= cnt1[p[1]];
		else ans -= cnt2[p_[1]];
		cout << ans << endl;
	}
	else {
		int ans = n - cnt1[p.front()] - cnt2[p_.front()];
		cout << ans << endl;
	}
	return 0;
}