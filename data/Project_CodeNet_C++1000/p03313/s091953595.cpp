#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=19,M=1<<N;
#define fi first
#define se second
typedef pair<int,int> P;
int n,v,ans[M];
P dp[M];
void merge(P &a,int x){
    if(x>=a.fi){
        a.se=a.fi;
        a.fi=x;
    }
    else if(x>a.se){
        a.se=x;
    }
}
int main(){
    scanf("%d",&n);
    dp[0]=P(-1,-1);
    for(int i=0;i<(1<<n);++i){
        scanf("%d",&v);
        dp[i]=P(v,-1);
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<(1<<n);++j){
            if(j>>i&1){//去掉1位的子集
                merge(dp[j],dp[j^(1<<i)].fi);
                merge(dp[j],dp[j^(1<<i)].se);
            }
        }
    }
    for(int j=1;j<(1<<n);++j){
        ans[j]=dp[j].fi+dp[j].se;
        ans[j]=max(ans[j],ans[j-1]);
        printf("%d\n",ans[j]);
    }
    return 0;
}
