#include <bits/stdc++.h>

using namespace std;

typedef multiset<int> :: iterator iter;
int n, k, q;
int f[20001];
int ans = 0x3f3f3f3f;
void add(int x) {
	for (; x <= n; x += (x & -x)) f[x] ++;
}

int query(int x) {
	int sum = 0;
	for (; x; x -= (x & -x)) sum += f[x];
	return sum;
}

pair<int, int> b[20001];
int a[20001];
multiset<int> S;

int main( ) {
	scanf("%d %d %d", &n, &k, &q);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]);
		b[i] = make_pair(a[i], i);
	}
	sort(b + 1, b + 1 + n);
	for (int i = 1; i <= n; i ++) {
		int cnt = 0;
		for (int j = i; j <= n; j ++) {
			int x = b[j].second, ta, tb;
			iter xx = S.upper_bound(x);
			if (xx == S.begin()) ta = 0;
			else ta = *(--xx);
			xx = S.upper_bound(x);
			if (xx == S.end()) tb = n + 1;
			else tb = (*xx);
			int gap = tb - ta - 1 - (query(tb - 1) - query(ta));
			if (gap >= k) {
				++ cnt;
				if (cnt == q) {
					ans = min(ans, b[j].first - b[i].first);
					break;
				}
				add(b[j].second);
			}
		}
		for (int j = 1; j <= n; j ++) f[j] = 0;
		S.insert(b[i].second);
	}
	printf("%d\n", ans);
	return 0;
}
