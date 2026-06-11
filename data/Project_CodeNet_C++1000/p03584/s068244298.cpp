#include<cstdio>
inline long long max(long long x,long long y){return x>y?x:y;}
int n,k,a[100001],b[100001];
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)scanf("%d%d",a+i,b+i);
	long long ans=0;
	for(int i=0;i<n;i++)
		if((a[i]&k)==a[i])ans+=b[i];
	if(!k){printf("%lld\n",ans);return 0;}
	int bit=0;
	while((1<<(bit+1))<=k)bit++;
	for(int i=bit;i>=0;i--)
		if(k&(1<<i))
		{
			long long x=0,mask=0;
			for(int j=bit;j>=i;j--)mask|=(1<<j)&k;
			mask--;
			for(int j=0;j<n;j++)
				if((a[j]&mask)==a[j])x+=b[j];
			ans=max(ans,x);
		}
	printf("%lld\n",ans);
	return 0;
}