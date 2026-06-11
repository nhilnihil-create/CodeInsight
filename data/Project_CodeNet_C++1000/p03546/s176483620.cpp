#include<bits/stdc++.h>
using namespace std;
int main()
{
	int c[10][10];
	int h,w;
	cin>>h>>w;
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			cin>>c[i][j];
		}

	}
	int a[h][w];
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
			cin>>a[i][j];
	}
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			for(int k=0;k<10;k++)
			{
				c[j][k]=min(c[j][k],c[j][i]+c[i][k]);
			}
		}
	}
	int cost=0;
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			if(a[i][j]!=-1)
			{
				cost += c[a[i][j]][1];
			}
		}
	}
	cout<<cost<<"\n";
}