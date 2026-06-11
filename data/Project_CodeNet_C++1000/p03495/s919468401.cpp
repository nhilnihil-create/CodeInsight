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
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0 ; i < n ; i++) cin >> a[i];
    sort(a, a + n);
    int b = 0;
    for (int i = 0 ; i < n ; i++) if (a[i] != a[i + 1]) b++;
	int c[b] = {}, j = 0;
	for (int i = 0 ; i < n ; i++) {
		c[j]++;
		if (a[i] != a[i + 1]) j++;
	}
	if (b <= k) {
		cout << 0;
		return 0;
	}
	sort(c, c + b);
	int d = 0;
	for (int i = 0 ; i < b - k ; i++) d += c[i];
	cout << d;
}