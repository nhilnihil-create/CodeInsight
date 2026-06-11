#include <bits/stdc++.h>
#define  ll      long long 
#define  int     ll 
#define  mod     1000000007
#define  pb      push_back
#define  pob     pop_back
#define  f1      first
#define  s2      second
#define  N       3003
#define  K       100005
#define  bol     (int)ceil((say-1)/2.0)
#define  PII     pair<int,int>
#define  PIII    pair<int,PII>
#define  PIIII   pair<PII,PII>
#define  PIIIII  pair<PIII,PII>
#define  PIIIIII pair<PIII,PIII>

using namespace std; 

char s[N];
int n;


int dp[N][N],pre[N][N];


int32_t main(){
    // freopen("a.gir","r",stdin);      
    // freopen("a.cik","w",stdout);
    scanf("%lld\n",&n);
    scanf("%s",s+2);

    dp[1][1]=1;
    for(int i=1;i<=n;i++){
        pre[1][i]=1;
    }

    for(int i=2;i<=n;i++){
        for(int j=1;j<=(i);j++){
            if(s[i]=='<'){
                dp[i][j]=pre[i-1][j-1];     
            }
            else if(s[i]=='>'){
                dp[i][j]=pre[i-1][i-1]-pre[i-1][j-1];
            }
            pre[i][j]=(pre[i][j-1]+dp[i][j])%mod;
        }
    }
    printf("%lld\n", (((pre[n][n])%mod)+mod)%mod);
}
