#include<cstdio>
const int N=200005;
int n,v[N],l,r,I,a,s[N][2],t;
inline int p1()
{
	for(int i=2;i<=n;++i)
		if(v[i]<=v[i-1])return 0;
	return 1;
}
inline int ck(int x)
{
	t=0;
	for(int i=1;i<=n;++i)if(v[i]<=v[i-1])
	{
		for(;s[t][0]>v[i];--t);
		for(int j=v[i],k=t;;--j,--k)
		{
			if(!j)return 0;
			else if(j!=s[k][0])
			{
				for(int w=t++;w>k;--w)
					s[w+1][0]=s[w][0],s[w+1][1]=s[w][1];
				s[k+1][0]=j,s[k+1][1]=2;break;
			}
			else if(s[k][1]<x){++s[k][1];break;}
			else s[k][1]=1;
		}
	}
	return 1;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&v[i]);
	if(p1())return printf("1"),0;
	for(l=2,r=n;l<=r;)
		ck(I=l+r>>1)?(a=I,r=I-1):(l=I+1);
	return printf("%d",a),0;
}