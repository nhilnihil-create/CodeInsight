#include <bits/stdc++.h>
const int maxn = 1e5 + 10;
char s[maxn];
int n;
void no() { puts("-1"); exit(0);}
int main()
{
	scanf("%s", s + 1);
	n = strlen(s + 1);
	if(s[1] == '0' || s[n] == '1') no();
	for(int i = 1, j = n - 1; i < j; ++i, --j)
		if(s[i] != s[j]) no();
	int cur = 1;
	for(int i = 1; i < n; ++i)
	{
		printf("%d %d\n", cur, i + 1);
		if(s[i] == '1') cur = i + 1;
	}
	return 0;
}