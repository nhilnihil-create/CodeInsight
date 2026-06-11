#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;
 
struct edge {
	int a, b;
	int len;
};
 
int main() {
	int l;
	scanf("%d", &l);
	int base = 1;
	int n = 0;
	while (base * 2 <= l) {
		base *= 2;
		n ++;
	}
	n ++;
	vector<edge> ans;
	vector<int> p(30);
	p[0] = 1;
	for (int i = 1; i < 30; i ++) {
		p[i] = 2 * p[i - 1];
	}
	for (int i = 0; i < n - 1; i ++) {
		ans.push_back({i, i + 1, 0});
		ans.push_back({i, i + 1, p[n - 2 - i]});
	}
	l -= base;
	int sum = base;
	for (int i = 30; i >= 0; i --) {
		if (l & (1 << i)) {
			ans.push_back({0, n - 1 - i, sum});
			sum += (1 << i);
		}
	}
	printf("%d %d\n", n, (int) ans.size());
	for (int i = 0; i < (int) ans.size(); i ++) {
		printf("%d %d %d\n", ans[i].a + 1, ans[i].b + 1, ans[i].len);
	}
        return 0;
}