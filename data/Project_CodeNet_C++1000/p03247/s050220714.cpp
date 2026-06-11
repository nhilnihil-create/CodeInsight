#include<cstdio>
#define N 1001
inline int abs(int x){return x<0?-x:x;}
inline int max(int x,int y){return x<y?y:x;}
int a[N],b[N],c[40],i,j,m,n,s;
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d%d",a+i,b+i),s=max(s,abs(a[i])+abs(b[i]));
	for(i=1;i<n;i++)if((a[i]^b[i]^a[i+1]^b[i+1])&1)return 0&puts("-1");
	while(1ll<<m<s)m++;
	for(s<2?m++:0,i=m;i--;)c[m-i]=1<<i;
	for(~(a[1]^b[1])&1?c[++m]=1:0,printf("%d\n",m),i=1;i<=m;i++)printf("%d%c",c[i],i==m?'\n':' ');
	for(i=1;i<=n;puts(""),i++)for(j=1;j<=m;j++)
	if(!a[i]&&!b[i]||a[i]+b[i]<0&&a[i]-b[i]<=0)a[i]+=c[j],putchar('L');
	else if(0<=a[i]+b[i]&&a[i]-b[i]<0)b[i]-=c[j],putchar('U');
	else if(0<a[i]+b[i]&&0<=a[i]-b[i])a[i]-=c[j],putchar('R');
	else if(a[i]+b[i]<=0&&0<a[i]-b[i])b[i]+=c[j],putchar('D');
	return 0;
}