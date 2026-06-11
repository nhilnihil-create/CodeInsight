#include<set>
#include<map>
#include<ctime>
#include<queue>
#include<cmath>
#include<climits>
#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
#define LL long long
using namespace std;
int read(){
    int f=1,x=0;char s=getchar();   
    while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}  
    while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
    return x*f;
}
#define MAXN 1000
#define INF 0x3f3f3f3f
int n,len,x[MAXN+5],y[MAXN+5],d[35];
void Print(int X,int Y){//贪心策略
	for(int i=1;i<=len;i++){
		if(abs(X)>abs(Y)){
			if(X>0) putchar('R'),X-=d[i];
			else putchar('L'),X+=d[i];
		}
		else{
			if(Y>0) putchar('U'),Y-=d[i];
			else putchar('D'),Y+=d[i];
		}
	}
	puts("");
	return ;
}
int main(){
	bool f[2]={0};
	n=read();
	for(int i=1;i<=n;i++)
		x[i]=read(),y[i]=read(),f[(x[i]+y[i])%2]=1;
	if(f[0]&&f[1]){//判断奇偶有无解
		puts("-1");
		return 0;
	}
	for(int i=30;i+1;i--)
		d[++len]=(1<<i);
	if(f[0]) d[++len]=1;//奇偶处理
	printf("%d\n",len);
	for(int i=1;i<len;i++)
		printf("%d ",d[i]);
	printf("%d\n",d[len]);
	for(int i=1;i<=n;i++)
		Print(x[i],y[i]);
	return 0;
}