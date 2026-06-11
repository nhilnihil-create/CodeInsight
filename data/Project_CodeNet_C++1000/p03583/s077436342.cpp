#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,i,j,a[10001]; 
int main()
{
	cin>>n;
	if(n&1==0)
	{
		cout<<n<<" "<<n<<" "<<n/2<<"\n";
		return 0;
	}
	if(n%3==0)
	{
		cout<<n<<" "<<n/3*2<<" "<<n/3*2<<"\n";
		return 0; 
	}
	if(n%4==3)
	{
		cout<<(n+1)/4<<" "<<(n+1)*(n+1)/4<<" "<<(n+1)*(n+1)*n/4<<"\n";
		return 0;
	}
	for(i=1;i<=3500;i++)
	{
		for(j=1;j<=3500;j++)
		{
			ll x,y;
			x=n*i*j;
			y=4*i*j-n*i-n*j;
			if(y>0&&x%y==0)
			{
				cout<<i<<" "<<j<<" "<<x/y<<"\n";
				return 0;
			}
		}
	}
	return 0;
}