#include<iostream>
#include<vector>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
using ll = long long;
using P = pair<string, int>;
#include<algorithm>
#include<math.h>
#include<map>
#include<queue>
#include<set>

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>>sw(m);
	rep(i, m) {
		int k;
		cin >> k;
		rep(j, k) {
			int s;
			cin >> s;
			s--;
			sw[i].push_back(s);
		}
	}
	vector<int>p(m);
	int ans(0);
	rep(i, m)cin >> p[i];
	for (int i = 0; i <(1<< n); ++i) {
		bool ok(true);
		rep(j, m) {
			int cnt(0);
			for (auto c : sw[j]) {
				if ((i >> c) & 1)cnt++;
			}
			if (cnt % 2 != p[j]) {
				ok = false;
				//cout << i;
			}
		}
		if (ok) {
			ans++;
			//cout << i << endl;
		}
	}
	cout << ans;
	return 0;
}