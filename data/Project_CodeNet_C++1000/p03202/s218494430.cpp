#include<bits/stdc++.h>
using namespace std;

int n,a[200010],l,r,mid,ans,p[6000010],pn,v[6000010];
bool bo;

bool check(int mid)
{
	p[pn=0]=0;
	for (int i=2; i<=n; i++)
		if (a[i]<=a[i-1])
		{
			while (p[pn]>a[i]) pn--;
			if (p[pn]==a[i])
			{
				v[pn]++;
				int nw=p[pn],nwp=pn;
				while (v[nwp]>mid)
				{
					v[nwp--]=1,nw--;
					if (!nw) return 0;
					if (p[nwp]==nw) v[nwp]++;
					else
					{
						nwp++;
						for (int j=pn; j>=nwp; j--) p[j+1]=p[j],v[j+1]=v[j];
						v[nwp]=2,p[nwp]=nw,pn++;
						break;
					}
				}
			} else p[++pn]=a[i],v[pn]=2;
		}
	return 1;
}

int main()
{
	scanf("%d",&n),bo=1,a[0]=0;
	for (int i=1; i<=n; i++) scanf("%d",&a[i]),bo&=(a[i-1]<a[i]);
	if (bo) return puts("1"),0;
	l=2,r=n;
	while (l<=r)
	{
		mid=(l+r)>>1;
		if (check(mid)) r=mid-1,ans=mid; else l=mid+1;
	}
	printf("%d\n",ans);
	return 0;
}