#include <bits/stdc++.h>
#define  ll      long long 
#define  int     ll 
#define  mod     1000000007
#define  pb      push_back
#define  pob     pop_back
#define  f1      first
#define  s2      second
#define  N       50
#define  K       100005
#define  bol     (int)ceil((say-1)/2.0)
#define  PII     pair<int,int>
#define  PIII    pair<int,PII>
#define  PIIII   pair<PII,PII>
#define  PIIIII  pair<PIII,PII>
#define  PIIIIII pair<PIII,PIII>

using namespace std; 


int n;
int dizi[N][N];
int dp[N][K];

int fun(int crr,int mask,int local,int ans,ll gcrr);
int dpf(int crr,int mask){
    if(crr>=(n+1)){
        return 0;
    }
    if(dp[crr][mask]!=-1)return dp[crr][mask];
    if(mask&(1<<crr))
        return dpf(crr+1,mask);

    dp[crr][mask]=fun(crr,mask,(1<<crr),0,crr);
    return dp[crr][mask];
}
int fun(int crr,int mask,int local,int ans,int gcrr){
    int mx=0,top;
    mx=max(mx,ans+dpf(gcrr+1,mask|local));
    for(int i=(crr+1);i<=(n);i++){
        if(mask&(1<<i))continue;
        top=0;
        for(int j=1;j<=n;j++){
            if(local&(1<<j)){
                top+=dizi[i][j];
            }
        }
        mx=max(mx,fun(i,mask,local|(1<<i),ans+top,gcrr));
    }
    // printf("%lld\n",mx );
    return mx;
}
int32_t main(){
    // freopen("a.gir","r",stdin);      
    // freopen("a.cik","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%lld",&dizi[i][j]);
        }
    }
    memset(dp,-1,sizeof(dp));
    printf("%lld\n", dpf(1,0));
}
