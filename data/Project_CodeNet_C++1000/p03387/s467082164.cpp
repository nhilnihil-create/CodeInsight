#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a[3],ans=0;
	for(int i=0;i<3;i++)
	cin>>a[i];
	sort(a,a+3);
	int x=a[0],y=a[1],z=a[2];
	x+=z-y;
	ans+=z-y;
	y=z;
	int k=y-x;
	
	if(k%2==0)
	cout<<ans+k/2;
	else
	cout<<ans+k/2+2;
}