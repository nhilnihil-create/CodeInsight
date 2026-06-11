#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
const int maxn=307;

char S[maxn];
int L,K;

int dp[maxn][maxn][maxn],V[maxn][maxn];

int main(){
        scanf("%s%d",S+1,&K);
        L=strlen(S+1);
        for(int i=1;i<=L;++i) for(int j=L;j;--j) for(int k=0;k<=K;++k){
                if(S[i]==S[j]){
                        dp[i][j][k]=dp[i-1][j+1][k]+1;
                }else{
                        dp[i][j][k]=max(dp[i-1][j][k],dp[i][j+1][k]);
                        if(k) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j+1][k-1]+1);
                }   
        }   
        for(int i=1;i<=L;++i) for(int j=L;j;--j){
                V[i][j]=max(max(V[i-1][j],V[i][j+1]),dp[i][j][K]);
        }   

        int ans=1;
        for(int i=2;i<L;++i) ans=max(ans,V[i-1][i+1]*2+1);
        for(int i=1;i<L;++i) ans=max(ans,V[i][i+1]*2);
        printf("%d\n",ans);
}
