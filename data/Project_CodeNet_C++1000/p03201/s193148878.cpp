#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int n, ans;
int a[maxn];
priority_queue<int> Q;
int main()
{
	scanf("%d", &n); 
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1, greater<int>());
	for(int i = 1; i <= n; ++i)
	{
		while(!Q.empty() && Q.top() > a[i]) Q.pop();
		if(!Q.empty() && Q.top() == a[i])
		{
			++ans;
			Q.pop();
			continue;
		}
		int k = 1 << (32 - __builtin_clz(a[i]));
		Q.push(k - a[i]);
	}
	printf("%d\n", ans);
	return 0;
}
		