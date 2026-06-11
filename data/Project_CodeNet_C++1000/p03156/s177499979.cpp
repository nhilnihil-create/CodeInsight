#include<iostream>
using namespace std;
#include <cstdio>
#include <cmath>
#include <cstring> 
#include <algorithm>
#include <stack> 
#define ll long long
int n,a,b,num;
int i1=0,i2=0,i3=0;
int findmin(void)
{
	int h[3];
	h[0]=i1;h[1]=i2;h[2]=i3;
	sort(h,h+3);
	return h[0];
}
int main()
{
	cin>>n>>a>>b;
	for(int i=0;i<n;i++)
	{
		cin>>num;
		if(num<=a)
		{
			i1++;
		}
		else if(num>b)
		{
			i3++;
		}
		else
		{
			i2++;
		}
	}
	cout<<findmin()<<endl;
	return 0;
	
}