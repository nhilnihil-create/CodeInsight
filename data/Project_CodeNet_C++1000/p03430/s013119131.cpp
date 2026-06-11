#include<bits/stdc++.h>
using namespace std;
int f[305][305][305],n,K;
char s[305];
inline int max(int x,int y){
	return x>y?x:y;
}
int main(){
  	scanf("%s%d",s+1,&K);
	n=strlen(s+1);
  	for(int i=1;i<=n;i++) for(int k=0;k<=K;k++) f[i][i][k]=1;
  	for(int l=2;l<=n;l++){
      	for(int i=1;i+l-1<=n;i++){
          	int j=i+l-1;
          	for(int k=0;k<=K;k++){
             	f[i][j][k]=max(f[i+1][j][k],f[i][j-1][k]);
                if(k) f[i][j][k]=max(f[i][j][k],f[i+1][j-1][k-1]+2);
                if(s[i]==s[j]) f[i][j][k]=max(f[i][j][k],f[i+1][j-1][k]+2);
          	}
    	}
  	}
  printf("%d\n",f[1][n][K]);
  return 0;
}