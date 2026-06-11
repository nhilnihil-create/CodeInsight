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
	int n;
	cin >> n;
	vector<string> S(n);
	rep(i, n) cin >> S[i];
	vector<int> cnt(n);
	int both = 0, head = 0, hip = 0;
	rep(i, n) {
		if (S[i].front() == 'B' && S[i].back() == 'A') both++;
		else if (S[i].front() == 'B') head++;
		else if (S[i].back() == 'A') hip++;
		rep(j, S[i].size() - 1) {
			if (S[i].substr(j, 2) == "AB") cnt[i]++;
		}
	}
	int ans = 0;
	if (both > 1) {
		ans += (both - 1);
		both = 1;
	}
	if (both == 1) {
		if (hip > 0 && head > 0) {
			ans += 2;
			hip--;
			head--;
		}
		else if (hip > 0 && head == 0) {
			ans++;
			hip--;
		}
		else if (hip == 0 && head > 0) {
			ans++;
			head--;
		}
	}
	ans += min(hip, head);
	rep(i, n) ans += cnt[i];
	dunk(ans);
	return 0;
}