#include <iostream>
#include <queue>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; i++)
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	int a[n];
	rep(i, n) scanf("%d", &a[i]);
	int num = min(n, k);
	int ans = 0;
	rep(i, num + 1) {
		rep(j, num - i + 1) {
			priority_queue<int, vector<int>, greater<int>> que;
			rep(l, i) que.push(a[l]);
			rep(l, j) que.push(a[n - 1 - l]);
			rep(l, k - i - j) {
				if (que.empty()) break;
				if (que.top() < 0)
					que.pop();
				else
					break;
			}
			int now = 0;
			while (!que.empty()) {
				now += que.top();
				que.pop();
			}
			ans = max(ans, now);
		}
	}
	printf("%d\n", ans);
	return 0;
}