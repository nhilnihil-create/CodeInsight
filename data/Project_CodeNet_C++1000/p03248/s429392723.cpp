#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100010;

char s[MAXN];
int n, fa[MAXN];

int main()
{
	scanf("%s", s + 1); n = strlen(s + 1);
	if(s[1] != '1' || s[n] != '0') return puts("-1"), 0;
	for(int i = 1; i <= n / 2; ++i)
		if(s[i] != s[n - i]) return puts("-1"), 0;
	int rt = 1, now = 1;
	for(int i = 2; i <= n; ++i)
		if(s[i] == '1')
		{
			now = i;
			for(int j = rt; j < now; ++j)
				printf("%d %d\n", j, now);
			rt = now;
		}
	printf("%d %d\n", n - 1, n);
	return 0;
}