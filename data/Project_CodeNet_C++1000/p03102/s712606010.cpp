#include <bits/stdc++.h>
using namespace std;
int main()
{
	long int n,m,c;
	cin>>n>>m>>c;
    long int i,j,b[m],a[n][m],x,d=0,y=0;
	for(i=0;i<m;i++)
	{
		cin>>b[i];
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			cin>>a[i][j];
		}
	}
	for(i=0;i<n;i++)
	{
		x=c;
		for(j=0;j<m;j++)
		{
			
			d=a[i][j]*b[j];
			x=x+d;
		}
		if(x>0)
		{
			y++;
		}
	}
	cout<<y<<endl;
}