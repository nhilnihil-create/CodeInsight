#include "bits/stdc++.h"
using namespace std;
int n, c[25], v[25];
int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", c + i);
	for(int i = 0; i < n; i++)
		scanf("%d", v + i);
	int ans = 0;
	for(int i = 0; i < n; i++)
		ans += max(0, c[i] - v[i]);
	printf("%d\n", ans);
}