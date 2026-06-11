#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 100010;
 
int a[N];
 
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	sort(a + 1, a + 1 + n);
	int ans = 0, nowm = 1e9;
	for(int i = 1; i < n; i++)
	{
		if(a[n] % 2 == 0)
		{
			if(abs(a[i] - a[n] / 2) < nowm)
			{
				nowm = abs(a[i] - a[n] / 2);
				ans = a[i];
			}
		}
		else
		{
			if(abs(a[i] - a[n] / 2) < nowm)
			{
				nowm = abs(a[i] - a[n] / 2);
				ans = a[i];
			}
			if(abs(a[i] - (a[n] / 2 + 1)) < nowm)
			{
				nowm = abs(a[i] - (a[n] / 2 + 1));
				ans = a[i];
			}
		}
	}
	printf("%d %d\n", a[n], ans);
}