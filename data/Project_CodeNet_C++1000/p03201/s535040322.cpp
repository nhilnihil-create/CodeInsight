#include <set>
#include <map>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 200100;

int n, a[N];
map < int, set <int> > m;

int main() {

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	sort(a, a + n);

	for (int i = 0; i < n; i++) {
		m[a[i]].insert(i);
	}

	int res = 0;

	for (int i = n - 1; i >= 0; i--) {
		if (m[a[i]].count(i) == 0) {
			continue;
		}
		m[a[i]].erase(i);
		int x = 1;
		while (x <= a[i]) {
			x <<= 1;
		}
		int d = x - a[i];
		if (m[d].size() > 0) {
			++res;
			m[d].erase(m[d].begin());
		}
	}

	printf("%d\n", res);

	return 0;

}