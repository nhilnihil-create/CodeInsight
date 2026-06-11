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
	int n;
	cin >> n;
	vector<int> a(110);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<int> ans;
	for (int i = 0; i < n; i++) {
		int o = 1000000007;
		for (int j = 0; j < n; j++) {
			if (j == a[j] - 1) {
				o = j;
			}
		}
		if (o == 1000000007) {
			cout << "-1" << endl;
			return 0;
		}
		ans.emplace_back(o + 1);
		a.erase(a.begin()+o);
	}
	for (int i = ans.size()-1; i >= 0; i--) {
		cout << ans[i] << endl;
	}
	return 0;
}
