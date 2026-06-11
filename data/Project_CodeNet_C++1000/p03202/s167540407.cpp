#include<cstdio>
#define N 200001
int a[N],i,l,n,r,o[N],p[N],q;
inline bool check(int s)
{
	if(s==1)
	{
		for(i=1;i<n;i++)if(a[i]>=a[i+1])return false;
		return true;
	}
	for(i=1,q=0;i<=n;i++)
	if(o[q]<a[i])o[++q]=a[i],p[q]=1;
	else
	{
		while(a[i]<o[q])q--;
		if(o[q]!=a[i])o[++q]=a[i],p[q]=2;
		else if(p[q]!=s)p[q]++;
		else
		{
			for(;o[q-1]+1==o[q]&&p[q-1]==s;q--);
			if(o[q-1]+1==o[q]&&q==1)return false;
			else if(o[q]==o[q-1]+1)p[q-1]++,o[q]=a[i],p[q]=1;
			else o[q]--,p[q]=2,o[++q]=a[i],p[q]=1;
		}
	}
	return true;
}
int main()
{
	scanf("%d",&n),l=1,r=n;
	for(i=1;i<=n;i++)scanf("%d",a+i);
	while(l<r)check(l+r>>1)?r=l+r>>1:l=l+r+2>>1;
	return 0*printf("%d\n",l);
}