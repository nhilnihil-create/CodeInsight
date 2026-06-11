#include <iostream>
#include <string>
#include <algorithm>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <deque>
#include <cstdio>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <cctype>
using namespace std;
int main() {
	int d, g;
	cin >> d >> g;
	pair<int, int> pa[11];
	for (int i = 0; i < d; i++) {
		cin >> pa[i].first >> pa[i].second;
	}
	bool ho[11];
	int ans = 1000000007;
	for (int bit = 0; bit < (1 << d); bit++) {
		for (int i = 0; i < d; i++) {
			if (bit & (1 << i)) {
				ho[i] = 1;
			}
			else {
				ho[i] = 0;
			}
		}
		int co = 0, co1 = 0;
		for (int i = 0; i < d; i++) {
			if (ho[i]) {
				co += ((i + 1) * 100) * pa[i].first + pa[i].second;
				co1 += pa[i].first;
			}
		}
		bool bo = true;
		for (int i = d - 1; i >= 0; i--) {
			if (co >= g && bo) {
				if (co1 < ans) {
					ans = co1;
					bo = false;
					break;
				}
			}
			if (ho[i] == false) {
				co1 += min(max(0,(g - co + ((i + 1) * 100) - 1) / ((i + 1) * 100)) , pa[i].first - 1);
				co += min(max(0, (g - co + ((i + 1) * 100) - 1) / ((i + 1) * 100)), pa[i].first - 1) * ((i + 1) * 100);
			}
		}
		if (co >= g && bo) {
			if (co1 < ans) {
				ans = co1;
			}
		}
	}
	cout << ans << endl;
}
