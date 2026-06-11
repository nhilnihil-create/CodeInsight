#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<set>
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;

int main() {
	int h, w;
	cin >> h >> w;
	vector<vector<int>> m(h, vector<int>(w));
	rep(i, h) {
		rep(j, w) {
			cin >> m[i][j];
		}
	}
	vector<pair<pair<int, int>, pair<int, int>>> ans;
	int cnt = 0;
	rep(i, w) {
		rep(j, h - 1) {
			if (m[j][i] % 2 == 1) {
				cnt++;
				ans.push_back(make_pair(make_pair(j + 1, i + 1), make_pair(j + 2, i + 1)));
				m[j][i]--;
				m[j + 1][i]++;
			}
		}
	}
	rep(i, w - 1) {
		if (m[h - 1][i] % 2 == 1) {
			cnt++;
            m[h-1][i+1]++;
			ans.push_back(make_pair(make_pair(h, i + 1), make_pair(h, i + 2)));
		}
	}
	cout << cnt << endl;
	rep(i, ans.size()) {
		cout << ans[i].first.first << " " << ans[i].first.second << " " << ans[i].second.first << " " << ans[i].second.second << endl;
	}
}
