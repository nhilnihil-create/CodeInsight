#include <bits/stdc++.h>
using namespace std;


#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

const int INF = 1e9+7;
using ipair = pair<int, int>;
using ll = long long;
bool operator>(const ipair a,const ipair b){return a.first > b.first;}


int main(){
    // Input
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];

    //
    vector<vector<ll>> dp(101, vector<ll>(2, -1));

    dp[45][0] = 0;
    for(int d=44; d>=0; --d){
        ll mask = 1LL<<d;
        ll num = 0;
        rep(i, N) if(A[i]&mask) ++num;

        if(dp[d+1][1] >= 0) chmax(dp[d][1], dp[d+1][1] + mask * max(num, N-num));
        if(dp[d+1][0] >= 0){
            if (K>>d & 1){
                chmax(dp[d][1], dp[d+1][0] + mask * num);
                chmax(dp[d][0], dp[d+1][0] + mask * (N-num));
            }else{
                chmax(dp[d][0], dp[d+1][0] + mask * num);
            }
        }
    }

    cout << max(dp[0][0], dp[0][1]) << endl;





    return 0;
}