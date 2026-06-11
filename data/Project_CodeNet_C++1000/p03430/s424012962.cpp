#include<bits/stdc++.h>
using namespace std;
const int N=305;
int f[N][N][N],n,K;char s[N];
int main(){
  scanf("%s%d",s+1,&K);n=strlen(s+1);
  for(int i=1;i<=n;i++)
      for(int k=0;k<=K;k++)f[i][i][k]=1;
  for(int len=2;len<=n;len++){
      for(int i=1;i+len-1<=n;i++){
          int j=i+len-1;
          for(int k=0;k<=K;k++){
              f[i][j][k]=max(f[i+1][j][k],f[i][j-1][k]);
              if(s[i]==s[j])f[i][j][k]=max(f[i][j][k],f[i+1][j-1][k]+2);
              if(k)f[i][j][k]=max(f[i][j][k],f[i+1][j-1][k-1]+2);
          }
      }
  }
  cout<<f[1][n][K]<<endl;
  return 0;
}