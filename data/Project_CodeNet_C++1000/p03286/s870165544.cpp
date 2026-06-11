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
     
     vector<int> vec(41,0);
     int n;
     cin>>n;
     if(n==0)
     {
		 cout<<0<<endl;
		 exit(0);
	 }
     while(n!=0)
     {
		 int index=solve(n);
		 vec[index]=1;
		 n-=power(-2,index);
	 }
	 int i,j;
	 for(j=40;j>=0;j--)
	 {
		 if(vec[j]==1)
		 {
			 break;
		 }
	 }
	 for(i=j;i>=0;i--)
	 {
		 cout<<vec[i];
	 }
	 cout<<endl;
}
