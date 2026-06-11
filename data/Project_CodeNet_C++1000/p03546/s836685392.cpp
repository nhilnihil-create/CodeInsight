#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
const int iINF = 1001001001;
const long long llINF = 1LL << 60;
map<int, int> mp;
int main()
{
	int h, w;
	cin >> h >> w;
	vector<vector<int>> dist(10, vector<int>(10, iINF));
	rep(i, 10) rep(j, 10) cin >> dist[i][j];
	rep(k, 10) {
		rep(i, 10) {
			rep(j, 10) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	int ans = 0;
	int tmp;
	rep(i, h) {
		rep(j, w) {
			cin >> tmp;
			if (tmp == -1)	continue;
			ans += dist[tmp][1];
		}
	}
	cout << ans << endl;
  return 0;
}
