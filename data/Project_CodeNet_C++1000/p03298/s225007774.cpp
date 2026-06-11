#include <bits/stdc++.h>

using namespace std;

int n;

char str[50];

map<pair<string, string>, int> ss; 

int main()
{
	scanf("%d", &n);
	scanf("%s", str);
	for (int i = 0; i < (1 << n); ++i)
	{
		string s, t;
		s.clear(), t.clear();
		for (int j = 0; j < n; ++j)
			if (i & (1 << j))
				s.push_back(str[j]);
			else
				t.push_back(str[j]);
		++ss[make_pair(s, t)];
	}
	long long ans = 0;
	for (int i = 0; i < (1 << n); ++i)
	{
		string s, t;
		s.clear(), t.clear();
		for (int j = 0; j < n; ++j)
			if (i & (1 << j))
				s.push_back(str[(n << 1) - 1 - j]);
			else
				t.push_back(str[(n << 1) - 1 - j]);
		ans += ss[make_pair(s, t)];
	}
	printf("%lld\n", ans);
	return 0;
}