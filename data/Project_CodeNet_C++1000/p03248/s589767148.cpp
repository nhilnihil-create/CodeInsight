#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	for (; ch < '0' || ch > '9'; ch = getchar()) if (ch == '-') f = -1;
	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = (x << 1) + (x << 3) + ch - '0';
	return x * f;
}

const int N = 1e5 + 5;
char s[N];

int main()
{
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	
	if (s[1] == '0') return puts("-1"), 0;
	if (s[n] == '1') return puts("-1"), 0;
	for (int i = 1; i < n; ++i)
		if (s[i] != s[n - i]) return puts("-1"), 0;
	
	int cur = 1;
	for (int i = 1; i < n; ++i)
	{
		printf("%d %d\n", cur, i + 1);
		if (s[i] == '1') cur = i + 1;
	}
	
	return 0;
}
