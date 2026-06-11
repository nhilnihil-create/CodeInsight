#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <bitset>

using namespace std;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, i, j, k, a, b, c, ans, p;
	cin >> n;
	vector<int> x(n);
	for (i = 0; i < n; i++) cin >> x[i];

	bool valid = true;
	for (i = 1; i < n; i++) {
		if (x[i] <= x[i - 1]) valid = false;
	}

	if (valid) ans = 1;
	else {
		a = 2; b = n * 2;
		while (a < b) {
			c = (a + b) / 2;
			bool solved = true;

			map<int, int> last, curr;
			last[x[0]] = 0;

			for (i = 1; i < n; i++) {
				if (x[i] > x[i - 1]) {
					swap(last, curr);
					curr[x[i]] = 0;
				}
				else {
					swap(last, curr);
					while (!curr.empty() && (curr.rbegin()->first > x[i])) curr.erase(curr.rbegin()->first);
					p = x[i];
					while (1) {
						curr[p]++;
						if (curr[p] >= c) {
							if (p == 1) {
								solved = false;
								break;
							}
							curr[p] = 0;
							p--;
						}
						else break;
					}
					if (!solved) break;
				}
				swap(last, curr);
			}

			if (solved) b = c;
			else a = c + 1;
		}
		ans = a;
	}

	cout << ans << "\n";

	return 0;
}

