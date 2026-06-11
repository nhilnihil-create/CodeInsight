#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int a[100010];
int main() {
	int n;
	scanf("%d", &n);
	int gap = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		gap = max(gap, a[i]);
	}
	int ch = -1;
	int cc = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == gap)continue;
		int cc1 = min(a[i], gap - a[i]);
		if (ch < cc1)
		{
			ch = cc1;
			cc = a[i];
		}
	}
	printf("%d %d\n", gap, cc);
}