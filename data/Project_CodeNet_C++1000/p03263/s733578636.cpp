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
const ll linf = (ll)4e18;
const int inf = 1001001001;
const int mod = 1000000007;

int mp[505][505];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int h, w;
	cin >> h >> w;
	rep(i, h)rep(j, w) cin >> mp[i][j];
	vector<tuple<int, int, int, int>> ans;
	rep(i, h) {
		if(i % 2 == 0) rep(j, w) {
			if (mp[i][j] % 2 == 0) continue;
			mp[i][j]--;
			if (j + 1 < w) {
				mp[i][j + 1]++;
				ans.emplace_back(i + 1, j + 1, i + 1, j + 2);
			}
			else if (i + 1 < h) {
				mp[i + 1][j]++;
				ans.emplace_back(i + 1, j + 1, i + 2, j + 1);
			}
		}
		else {
			for (int j = w - 1; j >= 0; --j) {
				if (mp[i][j] % 2 == 0) continue;
				mp[i][j]--;
				if (j - 1 >= 0) {
					mp[i][j - 1]++;
					ans.emplace_back(i + 1, j + 1, i + 1, j);
				}
				else if (i + 1 < h) {
					mp[i + 1][j]++;
					ans.emplace_back(i + 1, j + 1, i + 2, j + 1);
				}
			}
		}
	}
	cout << ans.size() << endl;
	rep(i, ans.size()) {
		printf("%d %d %d %d\n", get<0>(ans[i]), get<1>(ans[i]), get<2>(ans[i]), get<3>(ans[i]));
	}
	return 0;
}
