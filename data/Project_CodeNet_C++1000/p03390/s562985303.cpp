#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <iomanip>
using namespace std;
#define pb push_back
#define pf push_fron
#define INF 1e9
#define PI acos(-1)
typedef long long ll;

ll a[110], b[110];

int main() {
	
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		ll a, b;
		cin >> a >> b;
		if (a > b)swap(a, b);

		ll ans = 0;
		ans += 2 * (a - 1);
		if (a == b||a+1==b) {
			cout << ans << endl;
		}
		else {

			ll ok = 0;
			ll ng = b-a+1;
			while (abs(ok - ng) > 1) {
				ll mid = (ok + ng) / 2;
				if ((a+mid)*(a+mid) < a*b) {
					ok = mid;
				}
				else {
					ng = mid;
				}
			}
			ans += ((a+ok)*(a+ok+1)<a*b)?2*ok+1:2*(ok);
			if (ok == 0)ans = 2 * (a - 1)+1;
			cout << ans << endl;
		}
	}
	return 0;
}