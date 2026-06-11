#include<bits/stdc++.h>
int p[100],arr[]={1,4,7,9};
main()
{
	int t;
	for(int i = 0;i < 4;i++)
	{
		scanf("%d",&t);
		p[t]=1;
	}
	for(int i = 0;i < 4;i++)
	{
		if(p[arr[i]]==0)
		{
			printf("NO");
			return 0;
		}
	}
	printf("YES");
}