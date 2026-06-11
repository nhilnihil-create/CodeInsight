#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int a[N],n;
map<int,int>m;
inline int check(int mid)
{
	if(mid==1)
	{
		for(int i=1;i<n;i++)
			if(a[i]>=a[i+1])
				return 0;
		return 1;
	}
	m.clear();
	for(int i=2;i<=n;i++)
	{
		if(a[i]<=a[i-1])
		{
			m.erase(m.upper_bound(a[i]),m.end());
			int k=a[i];
			m[k]++;
			for(;k&&m[k]==mid;)
			{
				m.erase(k);
				k--;
				m[k]++;
			}
			if(!k)
				return 0;
		}
	}
	return 1;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",a+i);
	int l=1,r=n,mid;
	while(l<r)
	{
		mid=l+r>>1;
		if(check(mid))
			r=mid;
		else
			l=mid+1;
	}
	printf("%d\n",l);
	return 0;
}
