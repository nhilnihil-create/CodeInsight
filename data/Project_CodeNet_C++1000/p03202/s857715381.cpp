#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int a[maxn], s[maxn];
int n, top;
bool check(int k)
{
	top = 0;
	for(int i = 2; i <= n; ++i)
	{
		if(a[i - 1] < a[i]) continue;
		while(top && s[top] > a[i]) --top;
		s[++top] = a[i];
		while(top >= k && s[top - k + 1] == s[top])
		{
			int val = s[top];
			top -= k;
			s[++top] = val - 1;
			if(!s[top]) return 0;
		}
	}
	return 1;
}		
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	int l = 1, r = n;
	while(l <= r)
	{
		int mid = l + r >> 1;
		if(check(mid)) r = mid - 1;
		else l = mid + 1;
	}
	printf("%d\n", l);
	return 0;
}
/*
6
3 2 2 3 3 2
*/
	