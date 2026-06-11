#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <queue>
#include <cassert>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define ALL(a) (a).begin(), (a).end()
#define rALL(a) (a).rbegin(), (a).rend()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int iINF = 1001001001;
const long long llINF = 1LL << 60;
int main()
{
	// ABC128-C, 
	int n, m; cin >> n >> m;
	vector<int> k(m), p(m);
	vector<vector<int>> s(m);
	rep(i, m) {
		cin >> k[i];
		s[i].resize(k[i]);
		rep(j, k[i]) cin >> s[i][j];
	}
	rep(i, m) cin >> p[i];
	
	int ans = 0;
	rep(i, 1 << n) {
		bool ok = true;
		rep(j, m) {
			int num = 0;
			rep(l, n) {
				if (i >> l & 1) {
					rep(o, k[j]) {
						if (s[j][o] == l + 1) num++;
					}
				}
			}
			if (num % 2 != p[j]) {
				ok = false;
				break;
			}
		}
		if (ok) ans++;
	}
	cout << ans << endl;
	return 0;
}