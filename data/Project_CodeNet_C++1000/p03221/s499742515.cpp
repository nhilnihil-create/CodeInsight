#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <vector>
#include <climits>
#include <queue>
#include <utility>
#include <iomanip>
#include <sstream> 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
template<typename T1, typename T2>
inline void chmin(T1& a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2>
inline void chmax(T1& a, T2 b) { if (a < b) a = b; }
const ll MOD = 1000000007;
const ll INF = 1LL << 60;


int main()
{
	
	int n, m;
	cin >> n >> m;

	vector<int> p(m), y(m);

	rep(i, m) {
		cin >> p[i] >> y[i];
		p[i]--; y[i]--;
	}

	vector<vector<pair<int, int>>> dat(n);
	rep(i, m) {
		dat[p[i]].push_back(make_pair(y[i],i));
	}

	vector<pair<int, int>> ans(m);

	rep(i, n) {
		sort(dat[i].begin(), dat[i].end());
		rep(j, dat[i].size()) {
			ans[dat[i][j].second] = make_pair(i, j);
		}
	}

	rep(i, m) {
		printf("%06d%06d\n", ans[i].first+1, ans[i].second+1);
	}


}


