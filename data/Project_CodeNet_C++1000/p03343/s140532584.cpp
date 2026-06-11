#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define N 2005
using namespace std;

int n, k, Q, ans = 9e9, cnt, s, a[N];
vector<int> b, c;
int main()
{
	int i, j, w;
	cin >> n >> k >> Q;
	for (i = 1; i <= n; i++) scanf ("%d", &a[i]);
	for (i = 1; i <= n; i++) {
		s = 0;
		cnt = 0;
		b.clear();
		c.clear();
		for (j = 1; j <= n; j++) {
			if (a[j] >= a[i]) {
				cnt++;
				b.push_back(a[j]);
			} else {
				if (cnt >= k) {
					s += cnt - k + 1;
					sort(b.begin(), b.end());
					for (w = 0; w <= cnt - k; w++) c.push_back(b[w]);
				}
				cnt = 0;
				b.clear();
			}
		}
		if (cnt >= k) {
			s += cnt - k + 1;
			sort(b.begin(), b.end());
			for (w = 0; w <= cnt - k; w++) c.push_back(b[w]);
			b.clear();
		}
		cnt = 0;
		if (s >=Q) {
			sort(c.begin(),c.end());
			ans = min(ans, c[Q - 1] - a[i]);
		}
	}
	cout <<ans;
    return 0;
}
