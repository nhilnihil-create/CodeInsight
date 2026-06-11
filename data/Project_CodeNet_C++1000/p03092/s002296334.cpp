#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define mo 1000000007
#define maxn 1000000000000000000LL
#define pi 3.1415926535898
#define eps 1e-9 
using namespace std;
long long read(){
    long long xx=0,flagg=1;
    char ch=getchar();
    while((ch<'0'||ch>'9')&&ch!='-')
        ch=getchar();
    if(ch=='-'){
        flagg=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        xx=xx*10+ch-'0';
        ch=getchar();
    }
    return xx*flagg;
}
void pus(long long xx,long long flagg){
    if(xx<0){
        putchar('-');
        xx=-xx;
    }
    if(xx>=10)
        pus(xx/10,0);
    putchar(xx%10+'0');
    if(flagg==1)
        putchar(' ');
    if(flagg==2)
        putchar('\n');
    return;
}
long long n,a,b,i,j,p[5005],f[5005][5005],g[5005][5005];
long long minn(long long u,long long v){
	return u<v?u:v;
}
int main(){
	//freopen("buinss.in","r",stdin);
	//freopen("buinss.out","w",stdout);
	n=read();a=read();b=read();
	for(i=1;i<=n;i++)
		p[read()]=i;
	for(i=1;i<=n;i++)
		for(j=0;j<=n;j++){
			if(p[i]==j)
				f[i][j]=g[i-1][j];
			if(p[i]<j)
				f[i][j]=g[i-1][j]+a;
			if(p[i]>j)
				f[i][j]=g[i-1][j]+b;
			if(j==0)
				g[i][j]=f[i][j];
			else
				g[i][j]=minn(g[i][j-1],f[i][j]);
		}
	pus(g[n][n],2);
	return 0;
}