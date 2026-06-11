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
using namespace std;
typedef long long ll;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    int n, ans = 0;
    cin >> n;
    int a[n], b[100005];
    for (int i = 0 ; i < n ; i++) cin >> a[i];
    sort(a, a + n);
    for (int i = 1 ; i <= min(n, a[n - 1]) ; i++) b[i] = 0;
    for (int i = 0 ; i < n ; i++) {
    	if (a[i] > n) ans++;
    	else b[a[i]]++;
	}
    for (int i = 1 ; i <= min(n, a[n - 1]) ; i++) {
    	if (b[i] > 0) {
            if (i != b[i]) {
                if (b[i] > i) ans += b[i] - i;
                else ans += b[i];
            }
        }
	}
	cout << ans;
}