#include <sys/time.h>

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <utility>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <utility>
#include <cctype>

using namespace std;

using ll = long long;
using P = pair<double, double>;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define mkp(a, b) make_pair(a, b)
ll mod = 1000000007LL;



int main() {
	int n,c;
	cin >> n >> c;
	int d[c][c];
	int ct[c][3];
	rep(i,c) rep(j,3) { ct[i][j] = 0;}

	rep(i,c) rep(j,c) { cin >> d[i][j];}
	rep(i,n) rep(j,n) {
		int t;
		cin >> t;
		t--;
		ct[t][(i + j) % 3]++;
	}
	int ans = 1e9;


	rep(i, c) {
		int cur0 = 0;
		rep(l, c) {
			cur0 += d[l][i] * ct[l][0];
		}
		rep(j,c) {
			if (i == j) continue;
			int cur1 = cur0; 

			rep(l, c) {
				cur1 += d[l][j] * ct[l][1];
			}

			rep(k,c) {
				if (i == k || j == k) continue;
				int cur2 = cur1; 

				rep(l, c) {
					cur2 += d[l][k] * ct[l][2];
					//cout << "l:" << l << " d:" << d[l][k] << " ct:" <<  ct[l][2] << endl;
				}
				/*
				cout << "i:" << i << " " << cur0 << " ";
				cout << "j:" << j << " " << cur1 - cur0 << " ";
				cout << "k:" << k << " " << cur2 - cur1 << " " ;
				cout << "cur2:" << k << " " << cur2 << " " ;
				cout << endl;
				*/
				ans = min(cur2,ans);

			}
		}
	}
	cout << ans << endl;

	return 0;
}
