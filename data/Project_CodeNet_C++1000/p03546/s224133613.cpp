#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;
using P = pair<int,int>;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = 1<<30;
const ll mod = 1000000007LL;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    int H,W;
    cin>>H>>W;
    vector<vector<int>> dp(10,vector<int>(10,INF));
    rep(i,10){
        rep(j,10) cin>>dp[i][j];
    }
    map<int,int> A;
    rep(i,H){
        rep(i,W) {
            int x;
            cin>>x;
            A[x]++;
        }
    }
    rep(k,10){
        rep(i,10){
            rep(j,10) chmin(dp[i][j],dp[i][k]+dp[k][j]);
        }
    }
    int ans = 0;
    rep(i,10){
        ans+=A[i]*dp[i][1];
    }
    cout<<ans<<endl;
}