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
     int n;
     cin>>n;
     bool result=false;
     int j;
     for(j=0;j<=100;j++)
     {
		 for(int i=0;i<=100;i++)
		 {
			 if(4*j+7*i==n)
			 {
				 result=true;
			 }
		 }
	 }
	 if(result)
	    cout<<"Yes"<<endl;
	 else
	    cout<<"No"<<endl;
}
