#include <iostream>
#include<algorithm>
using namespace std;
int d[551][551];
int n,m,q;
void updata(int x,int y)
{
	int t;
	while(x>0)
	{
		t=y;
		while(t<=n)
		{
			d[x][t]++;
			t+=t&-t;
		}
		x-=x&-x;
	}
}
int que(int x,int y)
{
	int sum=0;
	int t;
	while(x<=n)
	{
		t=y;
		while(t>0)
		{
			sum+=d[x][t];
			t-=t&-t;
		}
		x+=x&-x;
	}
	return sum;
}
int main(int argc, char *argv[])
{
	cin>>n>>m>>q;
	int a,b;
	for(int i=1;i<=m;i++)
	{
		cin>>a>>b;
		updata(a,b);
	}
	for(int i=0;i<q;i++)
	{
		cin>>a>>b;
		cout<<que(a,b)<<endl;
	}
	return 0;
}