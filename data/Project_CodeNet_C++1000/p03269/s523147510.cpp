#include<bits/stdc++.h>
using namespace std;
const int N=1<<22;
int u[N],v[N],le[N];

int main()
{
	int l,m=0,n=1;
	scanf("%d",&l);
	for(int j=l;j;j/=3,n++);
	for(int i=0;l>=3;i++,l/=3)
	{
		for(int j=0;j<3;j++)
		{
			u[m]=i;
			v[m]=i+1;
			le[m++]=l/3*j;
		}
		for(int j=l/3*3;j<l;j++)
		{
			u[m]=i;
			v[m]=n-1;
			le[m++]=j;
		}
	}
	for(int i=0;i<l;i++)
	{
		u[m]=n-2;
		v[m]=n-1;
		le[m++]=i;
	}
	printf("%d %d\n",n,m);
	for(int i=0;i<m;i++)
	{
		printf("%d %d %d\n",u[i]+1,v[i]+1,le[i]);
	}
	return 0;
}