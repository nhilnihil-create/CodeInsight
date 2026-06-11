#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int MAX = 50;
/* global variables */
/* function */
/* main */
int main(){
    int N;
    ll K;
    cin >> N >> K;

    vector<ll> A(N); for(int i = 0; i < N; i++) cin >> A[i];
    vector<vector<ll> > dp(2, vector<ll>(100, -1));

    dp[1][0] = 0;
    for (int i = 0; i < MAX; i++) {
        ll mask = 1LL<<(MAX - i - 1);
        // A で元々 d 桁目にビットが立っているものの個数
        int num = 0;
        for (int i = 0; i < N; ++i) if (A[i] & mask) ++num;
        // X の d 桁目を 0, 1 にしたときのコスト
        ll cost0 = mask * num;
        ll cost1 = mask * (N - num);
        // smaller -> smaller
        if (dp[0][i] != -1) {
            dp[0][i+1] = max(dp[0][i+1], dp[0][i] + max(cost0, cost1)); // 0 でも 1 でも自在に大きい方
        }
        // exact -> smaller
        if (dp[1][i] != -1) {
            if (K & mask) { // K の d 桁目が 1 だったら、X の d 桁目は 0 にする
                dp[0][i+1] = max(dp[0][i+1], dp[1][i] + cost0);
            }
        }
        // exact -> exact (K にぴったり合わせる)
        if (dp[1][i] != -1) {
            if (K & mask) dp[1][i+1] = max(dp[1][i+1], dp[1][i] + cost1);
            else dp[1][i+1] = max(dp[1][i+1], dp[1][i] + cost0);
        }
    }

    cout << max(dp[0][MAX], dp[1][MAX]) << '\n';
}
