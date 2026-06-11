#include <bits/stdc++.h>
#include <string>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define ll long long

bool compare_by_b(pair<int, int> a, pair<int, int> b) {
	if (a.second != b.second) {
		return a.second > b.second;
	}
	else {
		return a.first > b.first;
	}
}

int main() {
	int n,m;
	ll ans;
	//入力
	cin >> n >> m;
	vector<int> a(n);
	vector<pair<int, int>> bc;
	rep(i, n) cin >> a[i];
	rep(i, m) {
		int b, c;
		cin >> b >> c;
		bc.push_back(pair<int, int>(b, c));
	}
	//sort:a()は昇順,bc()はsecondの逆順
	sort(a.begin(), a.end());
	sort(bc.begin(),bc.end(), compare_by_b);
	//先頭から割り当て
	ans = 0;
	int ap = 0;
	rep(i, bc.size()) {
		rep(j, bc[i].first) {
			if (a[ap] < bc[i].second) {
				a[ap] = bc[i].second;
			}
			ans += a[ap];
			if (ap+1 < n)
				++ap;
			else
				goto OWARI;
		}
	}
	for (int i = ap;i<n;++i)
		ans += a[i];
OWARI:

	cout << ans << endl;
}
