#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<queue>
#include<map>
using namespace std;
int v[55];
int main()
{
	int n,a,b,c,k;
	int ans=-10000000;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)
		scanf("%d",&v[i]);
	for(a=0;a<=k;a++)
	{
		for(b=0;b<=k;b++)
		{
			for(c=0;c<=k;c++)
			{
				if((a+b+c)<=k&&(a+b)>=c&&(a+b)<=n)
				{
					priority_queue<int> q;
					for(int i=0;i<a;i++)
						q.push(v[i]);
					for(int i=0;i<b;i++)
						q.push(v[n-i-1]);
					int sum=0;
					for(int i=0;i<a+b-c;i++)
					{
						sum+=q.top();
						q.pop();
					}
					ans=max(ans,sum);
				}
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}