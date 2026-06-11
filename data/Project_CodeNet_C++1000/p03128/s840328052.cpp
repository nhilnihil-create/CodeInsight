#include<bits/stdc++.h>
#define rep(i, n) for (int i=0;i<(n);i++)
using namespace std;
typedef long long ll;

ll INF=10000005;


int main(void){
    int n, m;
    cin>>n>>m;
    vector<int> dp(n+1, -INF);
    vector<int> v(m);
    rep(i, m) cin>>v[i];
    vector<int> num={2, 5, 5, 4, 5, 6, 3, 7, 6};
    dp[0]=0;
    for(int i=1;i<=n;i++){
        rep(j, m){
            int number=num[v[j]-1];
            if(i-number<0) continue;
            dp[i]=max(dp[i-number]+1, dp[i]);
        }
    }
    vector<int> ans(dp[n]);
    sort(v.begin(), v.end(), greater<int>());
    int matchnum=n;
    for(int i=1;i<=dp[n];i++){//最上位から数えて何桁目かを示している
        rep(j, m){//どの数字を使うかをループしている
            //cout<<i<<j<<endl;
            if(matchnum-num[v[j]-1]<0) continue;
            if(dp[matchnum-num[v[j]-1]]==dp[n]-i){
                //cout<<i<<", "<<j<<endl;
                ans[i-1]=v[j];
                matchnum-=num[v[j]-1];
                break;
            }
        }
    }
    //rep(i, n) cout<<dp[i]<<endl;
    rep(i, dp[n]) cout<<ans[i];
    cout<<endl;


}