#include<bits/stdc++.h>
using namespace std;

char s[202020];

int main()
{
	scanf("%s", s);
	int len = strlen(s);
	
	long long ans = 0, sum = 0;
	
	for(int i = 0; i < len; i++)
	{
		if(s[i] == 'A')
			sum++;
		else if(s[i] == 'B' && s[i + 1] == 'C')
		{
			ans += sum;
			i++;
		}
		else
		{
			sum = 0;
		}
	}
	printf("%lld\n", ans);
	return 0;
}