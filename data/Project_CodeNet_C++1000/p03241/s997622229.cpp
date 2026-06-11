#include<iostream>
using namespace std;
#include<map>
#include<vector>
#include<cmath>
#define int long long int
int power(int a,int b)
{
	int x=pow(a,b);
	return x;
}
int solve(int val)
{
	int j;
	if(val>0)
	{
		int sum=0;
		for(j=0;;j+=2)
		{
			sum+=power(2,j);
			if(sum>=val)
			{
				return j;
			}
		}
	}
	else
	{
		int sum=0;
		val*=-1;
		for(j=1;;j+=2)
		{
			sum+=power(2,j);
			if(sum>=val)
			{
				return j;
			}
		}
	}
}
int32_t main()
{
	int n,m;
	cin>>n>>m;
	int answer=1;
	int j;
	for(j=1;j*j<=m;j++)
	{
		if(m%j==0)
		{
			int p=j;
			int q=m/j;
			if(q>=n)
			{
				answer=max(answer,p);
			}
			if(p>=n)
			{
				answer=max(answer,q);
			}
		}
	}
	cout<<answer<<endl;
}
