#include <stdio.h>
#include <set>
#include <utility>

using namespace std;

typedef pair<int, int> ip;

int a[1 << 18], n;

set<ip> s[1 << 18];
int res[1 << 18];

int main() {
	scanf("%d", &n);
	int m = n;
	n = (1 << n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
		s[i].insert(ip(a[i], i));
	for (int i = 0; i < n; i++) {
		while (s[i].size() > 2) s[i].erase(s[i].begin());
		if (s[i].size() == 2) res[i] = (*s[i].begin()).first + (*s[i].rbegin()).first;
		for (int j = 0; j < m; j++) if ((i&(1 << j)) == 0) {
			for (set<ip>::iterator it = s[i].begin(); it != s[i].end(); it++)
				s[i | (1 << j)].insert(*it);
		}
	}
	for (int i = 1; i < n; i++) {
		if (res[i - 1] > res[i]) res[i] = res[i - 1];
		printf("%d\n", res[i]);
	}
	return 0;
}