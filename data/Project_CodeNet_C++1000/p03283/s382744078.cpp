#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll sum[501][501];
int n,m,q;


int main()
{
	cin >> n >> m >> q;
	for(int i = 0;i<m;i++)
	{
		int x,y;
		cin >> x >> y;
		sum[x][y]++;
	}

	for(int i = 0;i<500;i++)
	{
		for(int j = 0;j<501;j++)
		{
			sum[i+1][j]+=sum[i][j];
		}
	}
	for(int i = 0;i<500;i++)
	{
		for(int j = 0;j<501;j++)
		{
			sum[j][i+1]+=sum[j][i];
		}
	}
	for(int i = 0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			//cout<<sum[i][j]<<' ';
		}
		//cout<<endl;
	}
	for(int i = 0;i<q;i++)
	{
		int p,q;
		cin >>p>> q;
		p--;
		cout<<sum[q][q]-sum[p][q]-sum[q][p]+sum[p][p]<<endl;
	}
}