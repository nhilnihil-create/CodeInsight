#include <bits/stdc++.h>

using namespace std;

#define ll long long

signed main() {
	int n, k;
	cin >> n >> k;
	vector<ll> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	/* aの累積和sを計算する. */
	vector<ll> s(n + 1,0);
	for (int i = 0; i < n; ++i)
		s[i + 1] = s[i] + a[i];

	/* 連続する部分列の和をすべて求める. */
	vector<ll> cs;
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j <= n; ++j)
			cs.push_back(s[j] - s[i]);

	/* 最上位のビットmを決定する. */
	vector<int> ans; // 答えの立っているビット
	vector<ll> pos; // 最上位ビットの立っているものの集合
	for (int i = 40; i >= 0; --i) {
		vector<ll> ok; // 下からiビット目が立っているcs
		for (auto csi : cs)
			if (csi & (((ll)1) << i))
				ok.push_back(csi);
		if (ok.size() >= k) {
			pos = ok;
			ans.push_back(i);
			break;
		}
	}

	/* k個以上立っているビットがなければ必ず0. */
	if (pos.size() == 0) {
		cout << 0 << endl;
		return 0;
	}

	for (int i = ans[0] - 1; i >= 0; --i) {
		vector<ll> ok;
		for (auto posi : pos)
			if (posi & (((ll)1) << i))
				ok.push_back(posi);
		if (ok.size() >= k) {
			pos = ok;
			ans.push_back(i);
		}
	}

	ll answer = 0;
	for (auto ansi : ans)
		answer ^= ((ll)1 << ansi);

	cout << answer << endl;

	return 0;
}