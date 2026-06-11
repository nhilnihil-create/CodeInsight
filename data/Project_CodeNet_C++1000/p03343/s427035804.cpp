#include<bits/stdc++.h>
using namespace std;
int n,k,q,ans=1e9,t[2005],a[2005],b[2005],c[2005];
void cal(int m)
{
	int i,l=1,r=1;
	b[0]=0;
	while(l<=n)
	{
		c[0]=0;
		while(a[l]<m&&l<=n)l++;
		r=l;
		while(a[r]>=m&&r<=n)r++;
		for(i=l;i<r&&i<=n;i++)
			c[++c[0]]=a[i];
		if(c[0]>=k)
		{
			sort(c+1,c+c[0]+1);
			for(i=1;i<=c[0]-k+1;i++)
				b[++b[0]]=c[i];
		}
		l=r;
	}
	sort(b+1,b+b[0]+1);
	if(b[0]>=q)ans=min(ans,b[q]-b[1]);
}
int main()
{
	int i;
	cin>>n>>k>>q;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		t[i]=a[i];
	}
	sort(t+1,t+n+1);
	for(i=1;i<=n;i++)
		cal(t[i]);
	cout<<ans<<endl;
	return 0;
}