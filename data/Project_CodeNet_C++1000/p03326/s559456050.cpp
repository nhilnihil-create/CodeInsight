#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <string>
#include <math.h>
#include <set>
#include <deque>
#include <queue>
#include <list>
using namespace std;
typedef long long ll;
const int mod = 1000000007;

#define for1(n) for (int i = 0 ; i < n ; i++)
#define for2(n) for (int j = 0 ; j < n ; j++)
#define for3(n) for (int k = 0 ; k < n ; k++)
#define for4(n) for (int l = 0 ; l < n ; l++)
int main() {
    ios::sync_with_stdio(false);
    ll n, m, w = 0;
    cin >> n >> m;
    ll x[n], y[n], z[n];
    for1(n) cin >> x[i] >> y[i] >> z[i];
	for1(8) {
		ll a[1003] = {};
		for2(n) {
			if (i == 0) a[j] = x[j] + y[j] + z[j];
			else if (i == 1) a[j] = x[j] + y[j] - z[j];
			else if (i == 2) a[j] = x[j] - y[j] + z[j];
			else if (i == 3) a[j] = x[j] - y[j] - z[j];
			else if (i == 4) a[j] = -x[j] + y[j] + z[j];
			else if (i == 5) a[j] = -x[j] + y[j] - z[j];
			else if (i == 6) a[j] = -x[j] - y[j] + z[j];
			else if (i == 7) a[j] = -x[j] - y[j] - z[j];
		}
		sort(a, a + n);
		reverse(a, a + n);
		ll v = 0;
		for2(m) v += a[j];
		w = max(w, v);
	}
	cout << w;
}
/*
*/