#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a[3];
	cin>>a[0]>>a[1]>>a[2];
	sort(a,a+3);
	int x=a[0]%2,y=a[1]%2,z=a[2]%2;
	if((x&&y&&z)||!(x||y||z))
	{
		cout<<(2*a[2]-a[0]-a[1])/2<<'\n';
	}
	else
	{
		if(x==y)
		{
			a[0]++;
			a[1]++;
			
		}
		else if(x==z)
		{
			a[0]++;
			a[2]++;
		}
		else 
		{
			a[1]++;
			a[2]++;
		}
		cout<<(abs(a[2]-a[1])+abs(a[2]-a[0]))/2+1<<'\n';
	}
}