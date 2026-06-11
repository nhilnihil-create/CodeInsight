#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int et(int a, int b, int c, vector<int>l) {
	int ans = 10000;
	for (int i = 0; i < l.size() - 2; i++) {
		for (int j = i+1; j < l.size() - 1; j++) {
			for (int k = j + 1; k < l.size(); k++) {
				ans = min(ans, abs(l.at(i) - a) + abs(l.at(j) - b) + abs(l.at(k) - c));
			}
		}
	}
	return ans;
}

vector<vector<int>> mopt(int merge_x, vector<int>l) {
	vector<vector<int>>ans(0);
	ans.push_back(l);
	for (int i = 0; i < merge_x; i++) {
		int tmp = ans.size();
		for (int j = 0; j < tmp; j++) {
			for (int k = 0; k < ans.at(j).size() - 1; k++) {
				for (int t = k + 1; t < ans.at(j).size(); t++) {
					vector<int>res;
					for (int u = 0; u < ans.at(j).size(); u++) {
						if (u != k && u != t)res.push_back(ans.at(j).at(u));
					}
					res.push_back(ans.at(j).at(k) + ans.at(j).at(t));
					sort(res.begin(), res.end());
					reverse(res.begin(), res.end());
					ans.push_back(res);
				}
			}
		}
	}
	return ans;
}

int main() {
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	vector<int>l(n);
	for (int i = 0; i < n; i++)cin >> l.at(i);
	sort(l.begin(), l.end());
	reverse(l.begin(), l.end());
	int ans = et(a, b, c, l);
	int merge_x = ans / 10;
	merge_x = min(merge_x, n - 3);
	for (int i = 1; i <= merge_x; i++) {
		vector<vector<int>>merge_opt = mopt(i, l);
		for (int j = 0; j < merge_opt.size(); j++) {
			ans = min(ans, et(a, b, c, merge_opt.at(j))+10*i);
		}
	}
	cout << ans << endl;
}