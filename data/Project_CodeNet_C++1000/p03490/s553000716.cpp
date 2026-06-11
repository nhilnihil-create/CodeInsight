#include <bits/stdc++.h>
using namespace std;
const int maxn = 8000 + 10;
int n, x, y;
char s[maxn];
vector<int> a, b, c;
bool check(int x, vector<int> & a)
{
	bitset<maxn << 1> mask;
	mask[maxn] = 1;
	for(auto v : a)
		mask = (mask << v) | (mask >> v);
	if(0 <= x + maxn && x + maxn < (maxn << 1))
		return mask[x + maxn];
	else
		return 0;
}
int main()
{
	scanf("%s", s + 1);
	n = strlen(s + 1);
	int l = 0;
	while(l <= n)
	{
		int r = l + 1;
		while(r <= n && s[r] == 'F')
			++r;
		a.push_back(r - l - 1);
		l = r;
	}
	scanf("%d%d", &x, &y);
	x -= a[0];
	for(int i = 1; i < a.size(); ++i)
		if(i & 1)	
			b.push_back(a[i]);
		else
			c.push_back(a[i]);
	if(check(y, b) && check(x, c))
		puts("Yes");
	else
		puts("No");
	return 0;
}
		
	