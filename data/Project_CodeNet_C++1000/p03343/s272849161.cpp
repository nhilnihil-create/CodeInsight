#include <bits/stdc++.h>
using namespace std;

const int maxn = 2005;

int n, k, q;
int a[maxn];
set<int> st;

vector<int> solve(vector<int> v) {
	sort(v.begin(), v.end());
	int m = v.size();
	while(v.size() > m - k + 1) {
		v.pop_back();
	}
	if(v.size() < m - k + 1) {
		v.clear();
	}
	return v;
}

int main(int argc, char const *argv[])
{
	// freopen("in", "r", stdin);
	cin >> n >> k >> q;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		st.insert(a[i]);
	}
	int ans = INT_MAX;
	for(int lower : st) {
		std::vector<int> tmp;
		std::vector<int> all;
		for(int i = 1; i <= n + 1; i++) {
			if(a[i] < lower) {
				if(tmp.size()) {
					vector<int> ret = solve(tmp);
					for(int x : ret) {
						all.emplace_back(x);
					}
					tmp.clear();
				}
			} else {
				tmp.emplace_back(a[i]);
			}
		}
		sort(all.begin(), all.end());
		if(all.size() >= q) {
			ans = min(ans, all[q - 1] - lower);
		}
	}
	cout << ans << endl;
	return 0;
}