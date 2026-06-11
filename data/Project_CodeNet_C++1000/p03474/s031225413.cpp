#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	string s;
	cin >> s;
	int count = 0;
	rep(i, s.size())
	{
		if (s[i] == '-')
			count++;
	}
	if (count == 1)
	{
		if (a + b + 1 == s.size())
		{
			if (s[a] == '-')
			{
				printf("Yes\n");
				return 0;
			}
		}
	}
	printf("No\n");
	return 0;
}