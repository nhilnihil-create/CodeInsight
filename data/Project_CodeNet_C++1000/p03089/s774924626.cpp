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

#define mod 1000000007

int main() {
	int n;
	cin >> n;
	vector<int> b(n);
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		b[i]--;
	}
	vector<int> ans;
	while (!b.empty()) {
		for (int i = b.size() - 1; i >= 0; i--) {
			if (i == b[i]) {
				ans.push_back(b[i] + 1);
				b.erase(b.begin() + i);
				break;
			} else if (i == 0) {
				cout << -1 << endl;
				return 0;
			}
		}
	}
	for (int i = ans.size() - 1; i >= 0; i--) {
		cout << ans[i] << endl;
	}
}