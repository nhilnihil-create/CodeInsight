#include<bits/stdc++.h>
using namespace std;

map<int,int> mp;

main()
{
	for(int i=0;i<4;i++)
	{
		int n;
		scanf("%d",&n);
		if(n!=1&&n!=9&&n!=7&&n!=4)
		{
			printf("NO\n");
			return 0;
		}
		else
		{
			if(mp[n])
			{
				printf("NO\n");
				return 0; 
			}
			mp[n]++;
		}
	}
	printf("YES\n");
}
