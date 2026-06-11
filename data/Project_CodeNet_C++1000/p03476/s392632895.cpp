#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	//素数列取得
	vector<int>p = { 2,3 };
	for (int i = 3; i <= 100000; i++) {
		bool a = true;
		for (int j = 0; j < p.size(); j++) {
			if (i % p.at(j) == 0) {
				a = false;
				break;
			}
		}
		if (a)p.push_back(i);
	}
	set<int>ps;
	for (int i = 0; i < p.size(); i++)ps.insert(p.at(i));
	vector<int>ans;
	for (int i = 1; i < p.size(); i++) {
		if (ps.count((p.at(i) + 1) / 2))ans.push_back(p.at(i));
	}
	sort(ans.begin(), ans.end());
	//for (int i = 0; i < ans.size(); i++)cout << ans.at(i) << " ";
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		int s = lower_bound(ans.begin(), ans.end(), l) - ans.begin();
		int t = upper_bound(ans.begin(), ans.end(), r) - ans.begin();
		cout << t-s << endl;
	}

}