#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(ll i=0;i<n;i++)
#define Graph vector<vector<ll>>
#define INF (1ll<<60)
#define mod 1000000007
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    ll n,k;cin>>n>>k;
    vector<ll> a(n);
    rep(i,n) cin>>a[i];

    
    ll dp[50][2];// i桁目を見ている　smaller?
    rep(i,50) dp[i][false]=dp[i][true]=-1;//default
    dp[45][false]=0;//必ず0(大きいところは)

    for(ll i=44;i>=0;i--){
        ll twopow=1ll<<i;//高い桁から順に見る
        ll num=0;

        rep(j,n) if(a[j]&twopow) num++;//i桁目に立っているbitの数(a[i]に関して)

        if(dp[i+1][true]>=0){
            //前の桁smallerの時->max(今1のとき,今0のとき)
            chmax(dp[i][true],dp[i+1][true]+twopow*max(num,n-num));
            chmax(dp[i][false],dp[i+1][true]+twopow*max(num,n-num));
        }
        if(dp[i+1][false]>=0){
            if(k&twopow){//今見ている桁が1の時(k)
                
                //今の桁に対してsmallerの場合->0なので、i桁目の個数は不変でnumのまま
                chmax(dp[i][true],dp[i+1][false]+twopow*num);
                
                //一致する時->1なので、i桁目の個数はxor1によって変化し,n-num
                chmax(dp[i][false],dp[i+1][false]+twopow*(n-num));
            }else{//今見ている桁は0(k)
                
                //i桁目に関しては0しかないので一致しかない->i桁目不変
                chmax(dp[i][false],dp[i+1][false]+twopow*num);
            }
        }
    }

    cout<<max(dp[0][true],dp[0][false])<<endl;
    return 0;
}