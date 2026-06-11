#include <bits/stdc++.h>
using namespace std;

const int maxn = 220000;

int a[maxn];
long long s[maxn];
pair<long long, long long> lft[maxn], rgt[maxn];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for(int i = 0; i < n; ++ i) cin >> a[i];
	for(int i = 0; i < n; ++ i) s[i] = i == 0 ? a[i] : s[i - 1] + a[i];
	for(int i = 1; i < n; ++ i) {
		int pos = lower_bound(s, s + i, s[i] / 2) - s;
		if(pos < i) lft[i] = make_pair(s[pos], s[i] - s[pos]);
		else lft[i] = make_pair(s[pos - 1], s[i] - s[pos - 1]);
		if(pos && pos < i && abs(s[pos] - (s[i] - s[pos])) > abs(s[pos - 1] - (s[i] - s[pos - 1]))) {
			lft[i] = make_pair(s[pos - 1], s[i] - s[pos - 1]);
		}
	}
	reverse(a, a + n);
	for(int i = 0; i < n; ++ i) s[i] = i == 0 ? a[i] : s[i - 1] + a[i];
	for(int i = 1; i < n; ++ i) {
		int pos = lower_bound(s, s + i, s[i] / 2) - s;
		if(pos < i) rgt[i] = make_pair(s[pos], s[i] - s[pos]);
		else rgt[i] = make_pair(s[pos - 1], s[i] - s[pos - 1]);
		if(pos && pos < i && abs(s[pos] - (s[i] - s[pos])) > abs(s[pos - 1] - (s[i] - s[pos - 1]))) {
			rgt[i] = make_pair(s[pos - 1], s[i] - s[pos - 1]);
		}
	}
	reverse(rgt, rgt + n);
	long long ans = -1;
	for(int i = 1; i < n - 2; ++ i) {
		s[0] = lft[i].first;
		s[1] = lft[i].second;
		s[2] = rgt[i + 1].first;
		s[3] = rgt[i + 1].second;
		sort(s, s + 4);
		if(ans == -1 || ans > s[3] - s[0]) ans = s[3] - s[0];
	}
	cout << ans << "\n";
	return 0;
}
