#include<bits/stdc++.h>
using namespace std;
int s,a[4],x,y;
int main()
{
	for(int i=1;i<4;i++)
	{
		cin>>a[i];
		if(a[i]%2==0)y++;
		else x++;
	}
	sort(a+1,a+4);
	if(x==2)
	{
		for(int i=1;i<=3;i++)
		{
			if(a[i]%2!=0)a[i]++;
		}s=1;
	}
	if(y==2)
	{
		for(int i=1;i<=3;i++)
		{
			if(a[i]%2==0)a[i]++;
		}s=1;
	}
	for(int i=1;i<=3;i++)
	{
		s+=(a[3]-a[i])/2;
	}cout<<s;
}