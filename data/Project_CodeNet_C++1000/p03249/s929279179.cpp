#include<cstdio>
 
int n,nn;
struct node{int p,f,s;long long d,ss;};
node a[100010];
 
void qsort(int l,int r)
{
	int i,j;
	node m,t;
	i=l;j=r;
	m=a[(l+r)/2];
	while (i<=j)
	{
		while (a[i].d>m.d) i++;
		while (a[j].d<m.d) j--;
		if (i<=j)
		{
			t=a[i];a[i]=a[j];a[j]=t;
			i++;j--;
		}
	}
	if (l<j) qsort(l,j);
	if (i<r) qsort(i,r);
}

int find(long long x,int l,int r)
{
	int m=(l+r)/2;
	while (l<=r)
	{
		if (a[m].d==x) return m;
		if (a[m].d>x) l=m+1;
		else r=m-1;
		m=(l+r)/2;
	}
	return -1;
}
 
int main()
{
	scanf("%d",&n);
	nn=n-2;
	for (int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i].d);
		a[i].p=i;
		a[i].f=-1;
		a[i].s=1;
		a[i].ss=0;
	}
	qsort(1,n);
	bool ok=true;
	for (int i=1;i<n;i++)
	{
		long long fd=a[i].d-(n-a[i].s*2);
		int fn;
		fn=find(fd,i+1,n);
		if (fn==-1 || fd>a[i].d) {ok=false;break;}
		a[i].f=a[fn].p;
		a[fn].s+=a[i].s;
		a[fn].ss+=a[i].s+a[i].ss;
	}
	for (int i=1;i<=n;i++)
		if (a[i].f==-1 && a[i].ss!=a[i].d) {ok=false;break;}
	if (ok)
	{
		for (int i=1;i<=n;i++)
		{
			if (a[i].f!=-1) printf("%d %d\n",a[i].f,a[i].p);
		}
	}
	else printf("-1");
}