#include<iostream>
#include<algorithm>
#include<queue>
#include<string>
#include<unordered_map>
#include<map>
#include<cassert>
#include<deque>
#include<vector>
#include<random>
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
const long long inf = 1145141919810000;
typedef pair<int, int> P;
vector<P>V;
int nowh[200005];
signed main() {
	int h, w, n; cin >> h >> w >> n;
	rep(i, n) {
		int x, y; cin >> x >> y; V.push_back(P(x, y));
	}
	sort(V.begin(), V.end());
	V.push_back(P(inf, inf));
	nowh[1] = 1;
	int np = 0;
	for (int i = 2; i <= h; i++) {
		while (np < n&&V[np].first <= i) {
			if (V[np] == P(i, nowh[i - 1] + 1)) {
				nowh[i] = nowh[i - 1];
				goto X;
			}
			np++;
		}
		nowh[i] = nowh[i - 1] + 1;
		X:;
	}
	//rep(i, h)cout << nowh[i + 1] << endl;
	rep(i, n) {
		if (V[i].second <= nowh[V[i].first]) {
			cout << V[i].first - 1 << endl;
			return 0;
		}
	}
	cout << h << endl;
}
