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
	string s;
	cin >> n >> k >> s;
	vector<int> v;
	char prev = s[0];
	int cnt = 1;
	for (int i = 1; i < n; i++) {
		if (s[i] == prev) {
			cnt++;
		} else {
			v.push_back(cnt);
			cnt = 1;
			prev = s[i];
		}
	}
	v.push_back(cnt);
	vector<int> vsum(v.size() + 1, 0);
	for (int i = 1; i <= v.size(); i++) {
		vsum[i] = vsum[i - 1] + v[i - 1];
	}
	int ans = 0;
	if (s[0] == '0') {
		ans = vsum[min((int)v.size(), 2 * k)];
		for (int i = 1; i <= v.size(); i += 2) {
			ans = max(ans, vsum[min((int)v.size(), i + 2 * k + 1)] - vsum[i]);
		}
	} else {
		for (int i = 0; i <= v.size(); i += 2) {
			ans = max(ans, vsum[min((int)v.size(), i + 2 * k + 1)] - vsum[i]);
		}
	}
	cout << ans << endl;
}