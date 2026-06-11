#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int h, w, n, x, y;
char a[maxn], b[maxn];
void no() { puts("NO"); exit(0);}
int main()
{
	scanf("%d%d%d", &h, &w, &n);
	scanf("%d%d", &x, &y);
	scanf("%s%s", a + 1, b + 1);
	int s = 1, t = w;
	for(int i = n; i; --i)
	{
		if(b[i] == 'L') t = min(t + 1, w);
		if(b[i] == 'R') s = max(s - 1, 1);
		if(a[i] == 'L') ++s;
		if(a[i] == 'R') --t;
		if(s > t) no();
	}
	if(y > t || y < s) no();
	s = 1, t = h;
	for(int i = n; i; --i)
	{
		if(b[i] == 'U') t = min(t + 1, h);
		if(b[i] == 'D') s = max(s - 1, 1);
		if(a[i] == 'U') ++s;
		if(a[i] == 'D') --t;
		if(s > t) no();
	}
	if(x > t || x < s) no();
	puts("YES");
	return 0;
}
		