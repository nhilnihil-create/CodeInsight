#include<bits/stdc++.h>
inline int read(){
	char c=getchar();while (c!='-'&&(c<'0'||c>'9'))c=getchar();
	int k=1,kk=0;if (c=='-')c=getchar(),k=-1;
	while (c>='0'&&c<='9')kk=kk*10+c-'0',c=getchar();return kk*k;
}using namespace std;
void write(int x){if (x<0)putchar('-'),x=-x;if (x/10)write(x/10);putchar(x%10+'0');}
void writeln(int x){write(x);puts("");}
int f[310][310][310],kk,ans,l;
char s[1000];
signed main(){
	scanf("%s",s);kk=read();l=strlen(s);//f[i][j][k]为i到i+j-1最多修改k个后变成回文最少插入的个数 
	memset(f,10,sizeof(f));for (int i=0;i<=l+5;i++){
		memset(f[i][0],0,sizeof(f[i][0]));memset(f[i][1],0,sizeof(f[i][1]));
	}for (int j=2;j<=l;j++)
		for (int i=1;i+j-1<=l;i++)
			for (int k=0;k<=kk;k++){
				if (k)f[i][j][k]=f[i+1][j-2][k-1];
				if (s[i-1]!=s[i+j-2]){
					if (k)f[i][j][k]=min(f[i][j][k],f[i+1][j-2][k-1]);//修改一发 
				}else f[i][j][k]=min(f[i][j][k],f[i+1][j-2][k]);
				f[i][j][k]=min(f[i][j][k],min(f[i][j-1][k],f[i+1][j-1][k])+1);//插入一发
			}
	writeln(l-f[1][l][kk]);
}

