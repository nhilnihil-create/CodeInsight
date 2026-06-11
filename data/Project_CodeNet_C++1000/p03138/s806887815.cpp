#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); i++)
#define INF 10000000000
#define MOD 1000000007
using ll = long long;
using Graph = vector<vector<int>>;

ll dp[100][2];

int main(){
    int N;
    ll K; 
    cin>>N>>K;
    vector<ll> A(N);
    rep(i,N)cin>>A.at(i);

    rep(i,100)dp[i][0] = dp[i][1] = -1;
    dp[45][0] = 0;
    for(int d = 44; d >= 0; d--){
        ll mask = 1LL<<d;
        int num = 0; //d桁目の1の立ってる数
        rep(i,N)if(A[i]&mask)num++;

        if(dp[d+1][1] >= 0) dp[d][1] = max(dp[d][1],dp[d+1][1] + mask*max(num,N-num));
        if(dp[d+1][0] >= 0){
            if(K & mask){
                dp[d][1] = max(dp[d][1],dp[d+1][0]+mask*num);
                dp[d][0] = max(dp[d][0],dp[d+1][0]+mask*(N-num));
            }
            else {
                dp[d][0] = max(dp[d][0], dp[d+1][0]+mask*num);
            }
        }
    }
    cout<<max(dp[0][0],dp[0][1])<<endl;
}