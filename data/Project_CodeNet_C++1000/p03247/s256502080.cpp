#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Node
{
	int x, y;
}a[1010];
string ans[1010];
int n, cnt, d[45];

void solve(int x)
{
	d[++cnt] = x;
	for(int i = 1; i <= n; ++i)
	{
		if(abs(a[i].x) > abs(a[i].y))
		{
			if(a[i].x > 0) ans[i] += "R", a[i].x -= x;
			else ans[i] += "L", a[i].x += x;
		}
		else
		{
			if(a[i].y > 0) ans[i] += "U", a[i].y -= x;
			else ans[i] += "D", a[i].y += x;
		}
	}
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d %d", &a[i].x, &a[i].y);
	for(int i = 30; ~i; --i) solve(1 << i);
	if(a[1].x || a[1].y) solve(1);
	for(int i = 1; i <= n; ++i)
		if(a[i].x || a[i].y) return puts("-1"), 0;
	printf("%d\n", cnt);
	for(int i = 1; i <= cnt; ++i) printf("%d ", d[i]); puts("");
	for(int i = 1; i <= n; ++i) cout << ans[i] << "\n";
	return 0;
}