#include<bits/stdc++.h>
using namespace std;

main()
{
	int n;
	scanf("%d",&n);
	int bf=-1;
	int ans=0;
	for(int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		if(a==bf)
		{
			ans++;
			bf=-1;
		}
		else
		{
			bf=a;	
		}
	}
	printf("%d",ans);
}