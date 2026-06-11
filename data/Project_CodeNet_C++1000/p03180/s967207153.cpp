#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define mp make_pair
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fi first
#define se second
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
int n;
int a[20][20];
ll dp[1<<17];
ll dp2[1<<17];
ll go(int msk){
    //cout<<msk<<endl;
    if(dp2[msk]>=-1e17) return dp2[msk];
    dp2[msk]=dp[msk];
    /*for(int i=1;i<(1<<n);i++){
        if((i|msk)!=msk) continue;
        int res=msk-i;
        dp2[msk]=max(dp2[msk],go(i)+go(res));
    }*/
    for(int i=msk;i!=0;i=(i-1)&msk){
        if(i==msk) continue;
        int res=msk^i;
        dp2[msk]=max(dp2[msk],go(i)+go(res));
    }
    return dp2[msk];
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>a[i][j];
    memset(dp,-127,sizeof(dp));
    ll mx=0;
    for(int i=0;i<n;i++){
        dp[1<<i]=0;
        if(i==0) continue;
        for(int j=0;j<(1<<n);j++){
            if((j&(1<<i))==0) continue;
            if(j==(1<<i)) continue;
            int now=j^(1<<i);
            ll ha=0;
            for(int k=0;k<n;k++)
                if(now&(1<<k))
                    ha+=a[k][i];
            dp[j]=dp[now]+ha;
        }
    }
    memset(dp2,-127,sizeof(dp2));
    cout<<go((1<<n)-1)<<endl;
    return 0;
}
