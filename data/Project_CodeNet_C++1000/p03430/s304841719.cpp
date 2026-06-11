#define Kafuu signed
#define Chino main

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>

#define maxn 305
#define inf 0x3f3f3f3f
#define px putchar
#define pn px('\n')
#define ps px(' ')
#define pd puts("======================")
#define pj puts("++++++++++++++++++++++")

using namespace std;

inline int read(){
	int x=0,y=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')y=1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return y?-x:x;
}
template<typename T>
inline T read(){
	T x=0;
	int y=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')y=1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return y?-x:x;
}
int f[2][maxn][maxn];
char s[maxn];
Kafuu Chino(){
	scanf("%s",s+1);
	int n=strlen(s+1),k=read(),ans=0;
	for(register int i=1;i<=n;++i)f[0][i][i]=1;
	for(register int i=0;i<=k;++i){
		for(register int len=2;len<=n;++len)
			for(register int st=1,en=st+len-1;en<=n;++st,++en){
				f[i&1][st][en]=max(f[i&1][st+1][en],f[i&1][st][en-1]);
				if(s[st]==s[en])f[i&1][st][en]=max(f[i&1][st][en],f[i&1][st+1][en-1]+2);
				if(i)f[i&1][st][en]=max(f[i&1][st][en],f[i&1^1][st+1][en-1]+2);
			}
		ans=max(ans,f[i&1][1][n]);
	}
	printf("%d\n",ans);
}
