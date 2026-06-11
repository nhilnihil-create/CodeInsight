#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll f[1<<16],n,a[16][16],p[1<<16];
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>a[i][j];
	for(int i=0;i<(1<<n);i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i&(1<<j))
			{
				f[i]=f[i-(1<<j)];
				for(int k=0;k<n;k++)
				{
					if(i&(1<<k) && j!=k)
						f[i]+=a[j][k];
				}
			//	cout<<i<<' '<<f[i]<<endl;
			}
		}
	}
	for(int i=0;i<(1<<n);i++)
	{
		for(int j=i;j;j=(j-1)&i)
		{
			f[i]=max(f[i],f[j]+f[i^j]);
		}
	}
	cout<<f[(1<<n)-1]<<endl;
	return 0;
}
