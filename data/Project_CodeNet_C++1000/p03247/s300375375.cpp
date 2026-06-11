#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	long long x,y,u[n],v[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>x>>y;
		u[i]=x+y;
		v[i]=x-y;
	}
	long long r=((u[0]%2LL)+2LL)%2LL;
	for (int i = 1; i < n; ++i)
	{
		if (r!=((u[i]%2LL)+2LL)%2LL)
		{
			cout<<"-1\n";
			return 0;
		}
	}
	int m=31;
	if (r==0)
	{
		m=32;
	}
	cout<<m<<endl;
	long long d[m];
	d[0]=1LL;
	for (int i = 1; i < m; ++i)
	{
		if (i==1&&r==0)
		{
			d[1]=1LL;
			++i;
		}
		d[i]=d[i-1]*2LL;
	}
	reverse(d,d+m);
	cout<<d[0];
	for (int i = 1; i < m; ++i)
	{
		cout<<" "<<d[i];
	}
	cout<<endl;
	for (int i = 0; i < n; ++i)
	{
		char w[m];
		long long nu=0LL,nv=0LL;
		for (int j = 0; j < m; ++j)
		{
			if (nu>u[i])
			{
				if (nv>v[i])
				{
					w[j]='L';
					nu-=d[j];
					nv-=d[j];
				}
				else
				{
					w[j]='D';
					nu-=d[j];
					nv+=d[j];
				}
			}
			else
			{
				if (nv>v[i])
				{
					w[j]='U';
					nu+=d[j];
					nv-=d[j];
				}
				else
				{
					w[j]='R';
					nu+=d[j];
					nv+=d[j];
				}
			}
		}
		for (int j = 0; j < m; ++j)
		{
			cout<<w[j];
		}
		cout<<endl;
	}
	return 0;
}
