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

int main() {
	int n, k;
	cin >> n >> k;
	int x[50], y[50];
	long long int sortedx[50], sortedy[50];
	long long int ans = (long long int)4 * MOD * MOD;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
		sortedx[i] = x[i];
		sortedy[i] = y[i];
	}
	sort(sortedx, sortedx + n);
	sort(sortedy, sortedy + n);
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int p = 0; p < n; p++) {
				for (int q = p + 1; q < n; q++) {
					int cnt = 0;
					for (int r = 0; r < n; r++) {
						if (sortedx[i] <= x[r] && x[r] <= sortedx[j] &&
						    sortedy[p] <= y[r] && y[r] <= sortedy[q])
							cnt++;
					}
					if (cnt >= k) {
						ans = min(ans, (sortedx[j] - sortedx[i]) *
						                   (sortedy[q] - sortedy[p]));
					}
				}
			}
		}
	}
	cout << ans << endl;
}