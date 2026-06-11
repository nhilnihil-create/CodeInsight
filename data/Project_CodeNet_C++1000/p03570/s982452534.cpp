#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define fr(i,n) for(unsigned i=0;i<(n);++i)
#define Fr(i,n) for(int i=1;i<=(n);++i)
#define ifr(i,n) for(int i=(n)-1;i>=0;--i)
#define iFr(i,n) for(int i=(n);i>0;--i)
template<class T> void chmin(T&x,T y){if(x>y)x=y;}
template<class T> void chmax(T&x,T y){if(x<y)x=y;}

unsigned c,dp[1u<<26u],d[200001],n{};
int main(){
    d[0]=0;
    while((c=getchar_unlocked()-'a')<26) d[n+1]=d[n]^(1u<<c),++n;
    fill(dp,dp+(1u<<26u),500000);
    dp[d[n]]=0;
    ifr(i,n) fr(j,26) chmin(dp[d[i]],dp[d[i]^(1u<<j)]+1);
    printf("%d\n",max(dp[0],1u));
}