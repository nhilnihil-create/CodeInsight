#include <memory.h>

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

#define MOD 1000000007
#define INIT -1

int n, z, w;
int a[2000];

int main() {
	cin >> n >> z >> w;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int ans = abs(a[n - 1] - w);
	if (n > 1) ans = max(ans, abs(a[n - 1] - a[n - 2]));
	cout << ans << endl;
}