#include<bits/stdc++.h>
using namespace std;
int f[310][310][310],kk,ans,l;
char s[1000];
int main(){
	scanf("%s",s);scanf("%d",&kk);;l=strlen(s);
	memset(f,10,sizeof(f));for (int i=0;i<=l+5;i++){
		memset(f[i][0],0,sizeof(f[i][0]));memset(f[i][1],0,sizeof(f[i][1]));
	}for (int j=2;j<=l;j++)
		for (int i=1;i+j-1<=l;i++)
			for (int k=0;k<=kk;k++){
				if (k)f[i][j][k]=f[i+1][j-2][k-1];
				if (s[i-1]!=s[i+j-2]){
					if (k)f[i][j][k]=min(f[i][j][k],f[i+1][j-2][k-1]);
				}else f[i][j][k]=min(f[i][j][k],f[i+1][j-2][k]);
				f[i][j][k]=min(f[i][j][k],min(f[i][j-1][k],f[i+1][j-1][k])+1);
			}
	printf("%d\n",l-f[1][l][kk]);
}
