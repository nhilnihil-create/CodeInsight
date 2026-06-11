//羊肉串问题 
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
using namespace std;
int num[1005];
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)
		scanf("%d",&num[i]);
	int ans=-100000000;
	for(int a=0;a<=k;a++)
	{
		for(int b=0;b<=k;b++)
		{
			for(int c=0;c<=k;c++)
			{
				if((a+b+c)<=k&&(a+b)>=c&&(a+b)<=n)
				{
					priority_queue<int>q;
					for(int i=0;i<a;i++)
						q.push(num[i]);
					for(int i=0;i<b;i++)
						q.push(num[n-i-1]);
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