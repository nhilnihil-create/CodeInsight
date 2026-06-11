#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

int a[1000000],n;

int check(int m)
{
	int i;
	if(m==1)
	{
		for(i=1; i<n; ++i)
			if(a[i]>=a[i+1])
				return 0;
		return 1;
	}
	map<int,int> f;
	for(i=2; i<=n; ++i)
		if(a[i]<=a[i-1])
		{
			f.erase(f.upper_bound(a[i]),f.end());
			int k=a[i];
			++f[k];
			while(k>0&&f[k]==m)
				f.erase(k),++f[--k];
			if(!k)
				return 0;
		}
	return 1;
}

int main()
{
	cin>>n;
	int i;
	for(i=1; i<=n; ++i)
		scanf("%d",&a[i]);
	int l=1,r=n,m;
	while(l<r)
	{
		m=l+r>>1;
		if(check(m))
			r=m;
		else
			l=m+1;
	}
	cout<<l;
}
