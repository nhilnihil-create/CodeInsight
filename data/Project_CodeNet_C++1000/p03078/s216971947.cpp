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
	int x, y, z, k;
	cin >> x >> y >> z >> k;
	long long int a[1000], b[1000], c[1000];
	for (int i = 0; i < x; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < y; i++) {
		cin >> b[i];
	}
	for (int i = 0; i < z; i++) {
		cin >> c[i];
	}
	long long int ab[1000000];
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			ab[i * y + j] = a[i] + b[j];
		}
	}
	sort(c, c + z);

	long long int l = 0, r = (long long int)pow(10, 10) * 3000 + 1;
	while (r - l > 1) {
		long long int mid = (l + r) / 2;
		int cnt = 0;
		for (int i = 0; i < x * y; i++) {
			cnt += z - (lower_bound(c, c + z, mid - ab[i]) - c);
		}
		if (cnt >= k)
			l = mid;
		else
			r = mid;
	}

	vector<long long int> ans;
	for (int i = 0; i < x * y; i++) {
		for (int j = z - 1; j >= 0; j--) {
			if (ab[i] + c[j] < l + 1) break;
			ans.push_back(ab[i] + c[j]);
		}
	}
	while (ans.size() < k) ans.push_back(l);
	sort(ans.begin(), ans.end());
	reverse(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}
}