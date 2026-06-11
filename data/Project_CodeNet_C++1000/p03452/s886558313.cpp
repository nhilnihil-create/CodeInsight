#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m,x,y,z,fa[N],sum[N];
int Read()
{
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	return f*x;
}
int Get(int x)
{
	if(fa[x]==x) return x;
	int f=fa[x];
	fa[x]=Get(f);
	sum[x]+=sum[f];
	return fa[x];
}
void merge(int a,int b,int c)
{
	int f1=Get(a),f2=Get(b);
	fa[f1]=f2;
	sum[f1]=-sum[a]+sum[b]+c;
}
int main()
{
//	freopen("line.in","r",stdin);
	//freopen("line.out","w",stdout);
	n=Read(),m=Read();
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		x=Read(),y=Read(),z=Read();
		int f1=Get(x),f2=Get(y);
		if(f1==f2)
		{
			if(sum[x]-sum[y]!=z)
			{
				cout<<"No";
				return 0;
			}
		}
		else
		merge(x,y,z);
	}	
	cout<<"Yes";
	return 0;
}