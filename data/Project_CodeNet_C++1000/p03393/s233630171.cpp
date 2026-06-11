#include <bits/stdc++.h>
using namespace std;
const int maxn = 30;
char s[maxn];
bool vis[maxn];
int main()
{
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	if(n < 26)
	{
		for(int i = 1; i <= n; ++i) vis[s[i] - 'a'] = 1;
		for(int i = 0; i < 26; ++i)
			if(!vis[i])
			{
				s[n + 1] = 'a' + i;
				puts(s + 1);
				return 0;
			}
	}
	else
	{
		bool flag = 0;
		for(int i = n - 1; i; --i)
			if(s[i] < s[i + 1])
			{
				flag = 1;
				for(int j = n; j > i; --j)
					if(s[j] > s[i])
					{
						swap(s[j], s[i]);
						s[i + 1] = 0;
						break;
					}
				break;
			}
		if(!flag) puts("-1");
		else puts(s + 1);
		return 0;
	}
	return 0;
}
		
		
				
	
	 