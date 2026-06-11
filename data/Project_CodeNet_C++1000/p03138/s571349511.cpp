//#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>

using namespace std;


template<class T>
bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}


const int MAX_DIGIT = 50;
long long dp[100][2];

void solve() {
    long long N, K; cin >> N >> K;
    vector<long long> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    memset(dp, -1, sizeof(dp));

    dp[0][0] = 0;
    for (int d = 0; d < MAX_DIGIT; d++) {
        long long mask = 1LL << (MAX_DIGIT - d - 1);

        int num = 0;
        for (int i = 0; i < N; i++) {
            if (A[i] & mask) num++;
        }

        long long cost0 = mask * num;
        long long cost1 = mask * (N - num);

        // なんでもOK
        if (dp[d][1] != -1) {
            chmax(dp[d+1][1], dp[d][1] + max(cost0, cost1));
        }

        if (dp[d][0] != -1) {
            // d+1桁目をKより小さくして次からはなんでもOK
            if (K & mask) chmax(dp[d+1][1], dp[d][0] + cost0);

            // d+1桁目までKと一緒
            // 1
            if (K & mask) chmax(dp[d+1][0], dp[d][0] + cost1);
            // 0
            else chmax(dp[d+1][0], dp[d][0] + cost0);
        }
    }

    long long ans = max(dp[MAX_DIGIT][0], dp[MAX_DIGIT][1]);

    cout << ans << endl;
}


int main() {
    solve();
    return 0;
}