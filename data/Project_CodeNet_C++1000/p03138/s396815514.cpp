#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = 0; i <= (n); i++)
using namespace std;
typedef long long ll;
 
const ll INF = 1LL<<62;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using Graph = vector<vector<int>>;

typedef pair<int, int> P;
typedef priority_queue<int, vector<int>, greater<int>> PQ;
const int MOD = 1000000007;

int main(){
    ll N, K; cin >> N >> K;
    vector<ll> A(N);
    rep(i,N) cin >> A[i];

    vector<vector<ll>> dp(51, vector<ll>(2,-1));
    dp[0][0] = 0;
    for (int d = 0; d < 50; d++){
        ll mask = 1LL<<(50-d-1);
        int num = 0;
        // Aでd桁目にビットが立っているものの個数を算出
        for(int i = 0; i < N; ++i) if (A[i] & mask) ++num;

        // Xのd桁目を0,1にしたときのコスト
        ll cost0 = mask*num;
        ll cost1 = mask*(N-num);

        // i桁目がK未満の場合
        if (dp[d][1] != -1){
            dp[d+1][1] = max(dp[d+1][1], dp[d][1]+ max(cost0, cost1));
        }

        // i-1桁目がKでi桁目がK未満の場合
        if (dp[d][0] != -1){
            if (K & mask){
                dp[d+1][1] = max(dp[d+1][1], dp[d][0] + cost0);
            }
        }

        // i-1桁目もi桁目もKの場合
        if (dp[d][0] != -1){
            if (K & mask) dp[d+1][0] = max(dp[d+1][0], dp[d][0] + cost1);
            else dp[d+1][0] = max(dp[d+1][0], dp[d][0] + cost0);
        }
    }

    cout << max(dp[50][0], dp[50][1]) << endl;


}