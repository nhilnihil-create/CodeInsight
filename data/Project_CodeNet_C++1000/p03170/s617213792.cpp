#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); i++)
#define INF 10000000000
#define MOD 1000000007
using ll = long long;

int main(){
    int N,K; cin>>N>>K;
    vector<int> A(N);
    rep(i,N) cin>>A[i];
    vector<bool> dp(K+10,false);//dp[i]=falseとは石がi個あると必ず負ける
    // bool dp[110000];
    rep1(i,K){
        rep(j,N){
            // if(i>=A[j]) dp[i] |= !dp[i-A[j]];
            if(i>=A[j])  dp[i] = dp[i] || (!dp[i-A[j]]);
        }
        // cout<<dp[i]<<i<<endl;
    }

    // cout<<dp[K]<<endl;
    if(dp[K])cout<<"First"<<endl;
    else cout<<"Second"<<endl;
}

