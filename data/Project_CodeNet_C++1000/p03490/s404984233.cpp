#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define maxn 16005

int n,m;
bool f[maxn],g[maxn],tmp[maxn];
char s[maxn];

inline int read(){
	int x=0,f=1; char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') f=-1;
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x*f;
}

int main(){
	scanf("%s",s+1); n=strlen(s+1);
	int x=read()+8000,y=read()+8000;
	int l=1;
	for (;l<=n&&s[l]=='F';l++);
	f[l-1+8000]=1,g[8000]=1;
	int op=0;
	for (;l<=n;l++){
		if (s[l]=='T'){op^=1; continue;}
		bool *h=op?g:f; memset(tmp,0,sizeof(tmp)); int r=l;
		for (;r<=n&&s[r]==s[l];++r); --r; int pps=r-l+1;
		for (int i=pps;i<=16000-pps;i++) tmp[i]|=h[i-pps]|h[i+pps];
		for (int i=0;i<pps;i++) tmp[i]|=h[i+pps];
		for (int i=16001-pps;i<=16000;i++) tmp[i]|=h[i-pps];
		for (int i=0;i<=16000;i++) h[i]=tmp[i]; l=r;
	}
	puts((f[x]&&g[y])?"Yes":"No");
	return 0;
}
