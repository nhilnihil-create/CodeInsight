#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

const ll INF = -100000000000000;
ll dp[100001];//dp[i]ちょうどi本のマッチ棒を用いて，作れる最大の桁数
ll N,M,A[9];
ll SIZE[10] = {0,2,5,5,4,5,6,3,7,6};

int main(void){
    cin >> N >> M;
    rep(i,M)cin>>A[i];
    sort(A,A+M,greater<ll>());
    fill(dp,dp+N+1,INF);
    dp[0] = 0;
    
    for(ll i=1;i<=N;i++){
        rep(j,M){
            if(dp[i-SIZE[A[j]]] != INF && i>=SIZE[A[j]])dp[i] = max(dp[i],dp[i-SIZE[A[j]]]+1);
        }
    }
    //一桁ずつ確定していく
    ll i = N;
    while(i>0){
        rep(j,M){
            if(i>=SIZE[A[j]] && dp[i] == dp[i-SIZE[A[j]]]+1){
                cout << A[j];
                i -=SIZE[A[j]];
                break;
            }
        } 
    }
    cout << endl;
}
