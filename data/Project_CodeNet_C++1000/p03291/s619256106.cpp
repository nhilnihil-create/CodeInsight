#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
#define rep(i,n) for (ll i=0;i<n;++i)
#define rep2(i,a,b) for (ll i=a;i<b;++i)
const ll MOD=1000000007;

template<class T> inline bool chmin(T &a,T b){
    if (a>b){
        a=b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T &a,T b){
    if (a<b){
        a=b;
        return true;
    }
    return false;
}
//dp
int main(){
    string S;
    cin >> S;
    int s=S.size();
    vector<ll> sum(s+1,1);
    rep(i,s){
        sum[i+1]=sum[i];
        if (S[i]=='?'){
            sum[i+1]*=3;
            sum[i+1]%=MOD;
        }
    }
    vector<vector<ll>> dp(s+1,vector<ll>(3,0));
    dp[0][0]=dp[0][1]=dp[0][2]=0;
    rep(i,s){
        if (S[i]=='A'){
            dp[i+1][0]+=sum[i];
        }
        else if (S[i]=='B'){
            dp[i+1][1]+=dp[i][0];
        }
        else if (S[i]=='C'){
            dp[i+1][2]+=dp[i][1];
        }
        else {
            dp[i+1][0]+=sum[i]+dp[i][0]*2;
            dp[i+1][1]+=dp[i][0]+dp[i][1]*2;
            dp[i+1][2]+=dp[i][1]+dp[i][2]*2;
        }
        rep(j,3){
            dp[i+1][j]+=dp[i][j];
            dp[i+1][j]%=MOD;
        }
    }
    cout << dp[s][2] << endl;
}