#include<cstdio>
#include<algorithm>
int n,x[2010],y[2010],len,f[2010],d[2010];
void Print(int X,int Y){
	for(int i=1;i<=len;i++){
		if(abs(X)>abs(Y))
			if(X>0) putchar('R'),X-=d[i];
				else putchar('L'),X+=d[i];
		else if(Y>0) putchar('U'),Y-=d[i];
				else putchar('D'),Y+=d[i];
		
	}
	puts("");
	return ;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&x[i],&y[i]);
		f[(x[i]+y[i])%2]++;
	}
	if(f[1]&&f[0])return puts("-1"),0;
	for(int i=30;i>=0;i--)
		d[++len]=(1<<i);
	if(f[0])d[++len]=1;
	printf("%d\n",len);
	for(int i=1;i<=len;i++)
		printf("%d ",d[i]);
	puts("");
	for(int i=1;i<=n;i++)
		Print(x[i],y[i]);
}