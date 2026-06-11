/*
* @Author: 王文宇
* @Date:   2017-11-18 22:35:29
* @Last Modified by:   王文宇
* @Last Modified time: 2017-11-18 22:51:06
*/
#include <iostream>
using namespace std;
int a[11][11];
int n,m;
int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			for(int k=0;k<10;k++)
			{
				a[j][k]=min(a[j][k],a[j][i]+a[i][k]);
			}
		}
	}
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		for(int k=1;k<=m;k++)
		{
			int x;
			cin>>x;
			if(x!=-1&&x!=1)sum+=a[x][1];
		}
	}
	cout<<sum<<endl;
	return 0;
}