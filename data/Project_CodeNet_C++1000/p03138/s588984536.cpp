#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define VS vector<string>
#define VB vecctor<bool>
#define VP vector<pair<ll,ll>>
#define VVL vector<vector<ll>>
#define VVP vector<vector<pair<ll,ll>>>
#define PL pair<ll,ll>
ll d1[4] = {1, -1, 0, 0};
ll d2[4] = {0, 0, 1, -1};

int main(){
    ll N, K;
    cin >> N >> K;
    VL A(N);
    rep(i, 0, N) cin >> A[i];

    VVL dp(100, VL(2, -1));
    dp[0][0] = 0;

    rep(d, 0, 50){
        ll mask = 1LL<<(50-d-1);

        ll c = 0;
        rep(i, 0, N) if(A[i] & mask) c++;

        ll c0 = c * mask;
        ll c1 = (N - c) * mask;

        if(dp[d][1] != -1){
            dp[d+1][1] = max(dp[d+1][1], dp[d][1] + max(c0, c1));
        } 

        if(dp[d][0] != -1){
            if(K & mask){
                dp[d+1][1] = max(dp[d+1][1], dp[d][0] + c0);
            }
        }

        if(dp[d][0] != -1){
            if(K & mask) dp[d+1][0] = max(dp[d+1][0], dp[d][0] + c1);
            else dp[d+1][0] = max(dp[d+1][0], dp[d][0] + c0);
        }
    }

    cout << max(dp[50][0], dp[50][1]) << endl;
    return 0;
}