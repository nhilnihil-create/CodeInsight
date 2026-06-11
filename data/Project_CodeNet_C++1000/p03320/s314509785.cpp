#include<bits/stdc++.h>
using namespace std;
const int a[] = {1,2,3,4,5,6,7,8,9,19,29,39,49,59,69,79,89,99,199,299,399,499,599,699,799,899,999};
int main()
{
	int k;
	scanf("%d", &k);
	if(k <= 27)
	{
		for(int i = 0; i < k; ++ i)
			printf("%d\n", a[i]);
		return 0;
	}
	k -= 27;
	for(int i = 0; i < 27; ++ i)
		printf("%d\n", a[i]);
	for(int i = 4; i <= 14; ++ i)
	{
		for(int j = 10; j < min(100, (i - 2) * 10); ++ j)
		{
			printf("%d", j);
			for(int q = 1; q <= i - 2; ++ q)
				putchar('9');
			puts("");
			-- k;
			if(k == 0)
				return 0;
		}
		for(int j = i - 2; j <= 9; ++ j)
		{
			printf("%d", j);
			for(int q = 1; q <= i - 1; ++ q)
				putchar('9');
			puts("");
			-- k;
			if(k == 0)
				return 0;
		}
	}
	for(int i = 100; i <= 108; ++ i)
	{
		printf("%d", i);
		for(int j = 1; j <= 12; ++ j)
			putchar('9');
		puts("");
		-- k;
		if(k == 0)
			return 0;
	}
	for(int i = 10; i <= 99; ++ i)
	{
		printf("%d", i);
		for(int j = 1; j <= 13; ++ j)
			putchar('9');
		puts("");
		-- k;
		if(k == 0)
			return 0;
	}
	return 0;
}