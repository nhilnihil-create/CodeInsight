#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
void print(int a,int b,int c)
{
	cout<<a<<" "<<b<<" "<<c<<endl;
}
void solve()
{
	for(int i=1;i<=3500;i++)
	{
		for(int j=1;j<=3500;j++)
		{
			int c=n*i*j;
			int m=4*i*j-n*i-n*j;
			if(m>0&&c%m==0)
			{
				print(i,j,c/m);
				return;
			}
		}
	}
}
signed main()
{
	cin>>n;
	if(n%2==0)
	{
		print(n,n,n/2);
		return 0;
	}
	if(n%3==0)
	{
		print(n,n/3*2,n/3*2);
		return 0;
	}
	if((n-3)%4==0)
	{
		print((n+1)/4,(n+1)*(n+1)/4,(n+1)*(n+1)*n/4);
		return 0;
	}
	solve();
	return 0;
}