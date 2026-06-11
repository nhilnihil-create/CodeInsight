#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <stdlib.h>
#include <string.h>
#include <cmath>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <set>
const int MOD = 1e9 + 7;
using namespace std;
typedef long long ll;

map<ll, int> mp;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int a, b, k;
	cin >> a >> b >> k;
	for (int i = 0; i < k; i++) {
		if (i % 2 == 0) {
			if (a % 2 == 1) a--;
			b += a / 2;
			a /= 2;
		}
		else {
			if (b % 2 == 1) b--;
			a += b / 2;
			b /= 2;
		}
	}
	cout << a << " " << b << endl;
	return 0;
}