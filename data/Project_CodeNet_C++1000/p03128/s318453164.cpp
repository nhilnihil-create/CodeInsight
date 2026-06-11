#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i < (int)(n); i++)
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;

vector<string> dp(10010);

string compare_str(string now, string before, int n) {
    if (now == "impossible") now = "";
    if (now.size() > before.size() + 1) return now;
    if (now.size() < before.size() + 1) return to_string(n) + before;
    bool now_large = true;
    rep(i, now.size()) {
        int int_now = now[i] - '0', int_before;
        if (i==0) int_before = n;
        else int_before = before[i-1] - '0';

        if (int_now < int_before) {
            now_large = false;
            break;
        } else if (int_now > int_before) {
            now_large = true;
            break;
        }
    }

    if (now_large) return now;
    else return to_string(n) + before;
}

int main() {
    int N, M, ai;
    cin >> N >> M;
    bool A[10] = {};
    rep(i, M) cin >> ai, A[ai] = true;

    rep(i, N+1) dp[i] = "impossible";
    dp[0] = "";
    rep(k, N+1) {
        if (dp[k] != "impossible"){
            if (A[1]) dp[k+2] = compare_str(dp[k+2], dp[k], 1);
            if (A[2]) dp[k+5] = compare_str(dp[k+5], dp[k], 2);
            if (A[3]) dp[k+5] = compare_str(dp[k+5], dp[k], 3);
            if (A[4]) dp[k+4] = compare_str(dp[k+4], dp[k], 4);
            if (A[5]) dp[k+5] = compare_str(dp[k+5], dp[k], 5);
            if (A[6]) dp[k+6] = compare_str(dp[k+6], dp[k], 6);
            if (A[7]) dp[k+3] = compare_str(dp[k+3], dp[k], 7);
            if (A[8]) dp[k+7] = compare_str(dp[k+7], dp[k], 8);
            if (A[9]) dp[k+6] = compare_str(dp[k+6], dp[k], 9);
        }
        // rep(i, N+1) cout << dp[i] << ",";
        // cout << endl;
    } 

    cout << dp[N] << endl;

    return 0;
}

 