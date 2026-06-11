#include <iostream>
#include <cstring>
#include <queue>
#define LL long long
#define MAXN (1000000 + 5)
using namespace std;
int n;
LL fr[MAXN];
char s[MAXN];
void solve(int k) {
	LL dqd = 0, ans = 0;
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (s[i] == 'M')	q.push(i), dqd += fr[i];
		if (s[i] == 'C') {
			while (!q.empty() && i - q.front() >= k)
				dqd -= fr[q.front()], q.pop();
			ans += dqd - fr[max(0, i - k)] * q.size();	
		}
	}
	printf("%lld\n", ans);
}
int main() {
	scanf("%d", &n);
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i++)
		fr[i] = fr[i - 1] + (s[i] == 'D');
	int q;
	scanf("%d", &q);
	for (int i = 1, srq; i <= q; i++)
		scanf("%d", &srq), solve(srq);
	return 0;
}
