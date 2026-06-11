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
using namespace std;
typedef long long ll;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    int n, h;
    cin >> n >> h;
    int a[n], b[n], m = 0, d = 0;
    for (int i = 0 ; i < n ; i++) cin >> a[i] >> b[i], m = max(m, a[i]);
    sort(b, b + n);
    for (int i = n - 1 ; i >= 0 ; i--) {
    	if (b[i] < m) break;
    	h -= b[i];
    	d++;
    	if (h <= 0) {
            cout << d;
            return 0;
        }
	}
	if (h % m == 0) cout << d + h / m;
	else cout << d + h / m + 1;
}