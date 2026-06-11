#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int cnt[105];
int dp[105][80];

int main(){
    int n;
    cin>>n;
    rep(i,105)cnt[i]=1;
    for(int i=1; i<=n; ++i){
        int x=i;
        for(int j=2; j*j<=x; ++j){
            while(x%j==0){
                x/=j;
                cnt[j]++;
            }
        }
        if(x!=1)cnt[x]++;
    }
    dp[0][1]=1;
    for(int i=0; i<n; ++i){
        for(int j=1; j<=75; ++j){
            for(int k=1; k<=cnt[i]; ++k){
                if(j*k>75)continue;
                dp[i+1][j*k]+=dp[i][j];
            }
        }
    }
    cout<<dp[n][75]<<endl;
}