#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#define ll long long
using namespace std;
int main()
{
	int n,k,sum_max=-99999999,i,j,a,b,c;
	int f[1000];
	cin>>n>>k;
	for(i=0;i<n;i++)
	{
		cin>>f[i];
	}
	for(a=0;a<=k;a++)
	{
		for(b=0;b<=k;b++)
		{
			for(c=0;c<=k;c++)
			{
				if(a+b+c<=k && a+b>=c && a+b<=n)
				{
					priority_queue<int>q;
					for(i=0;i<a;i++)
					{
						q.push(f[i]);
					}
					for(i=0;i<b;i++)
					{
						q.push(f[n-i-1]);
					}
					int sum=0;
					for(i=0;i<a+b-c;i++)
					{
						sum+=q.top();
						q.pop();
					}
					sum_max=max(sum_max,sum);
				}
			}
		}
	}
	cout<<sum_max<<endl;
	return 0;
} 