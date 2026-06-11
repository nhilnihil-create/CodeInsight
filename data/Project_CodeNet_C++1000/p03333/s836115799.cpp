#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <queue>
 
using namespace std;
 
typedef long long ll;
 
const ll INF = 1e9, MOD = 1e9 + 7, MOD2 = 1e6 + 3;

int l[1000000], r[1000000], n;

int main () {

	cin >> n;

	for (int i = 0; i < n; i++)
		scanf ("%d%d", &l[i], &r[i]);

	sort (l, l + n + 1);
	sort (r, r + n + 1);
	reverse (l, l + n + 1);

	ll ans = 0, sum = 0;

	for (int i = 0; i <= n; i++) {
		sum += 2 * (l[i] - r[i]);
		ans = max (ans, sum);
	}

	cout << ans;
}