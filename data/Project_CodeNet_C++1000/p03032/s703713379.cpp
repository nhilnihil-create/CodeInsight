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
	int n, k;
	cin >> n >> k;
	
	vector<int> vs(n);
	rep(i, n) {
		cin >> vs[i]; 
	}

	int ans = 0;
	int max_l = min(k, n + 1);


	rep(l, max_l + 1) {
		vector<int> vrs;
	
		int cur_k_l = k - l;
		rep(i,l) {
			vrs.push_back(vs[i]); 			
		}

		int max_r = min(cur_k_l, n - l);
		rep(r, max_r + 1) {
			int cur_k_r = cur_k_l - r;


			vector<int> vrls = vrs;

			rep(i, r) {
				vrls.push_back(vs[vs.size() - i - 1]);
			}

			sort(vrls.begin(), vrls.end());
			
			int total = 0;
			rep(i, vrls.size()) {
				if (cur_k_r > 0 && vrls[i] < 0) {
					cur_k_r--;
					continue;
				}
				total += vrls[i];
			}
			//cout << "l:" << l << " r:" << r << " vrls.size():" << vrls.size();
			//cout << " total:" << total << endl; 

			ans = max(total, ans);
		}
	}
	cout << ans << endl;

	return 0;
}
