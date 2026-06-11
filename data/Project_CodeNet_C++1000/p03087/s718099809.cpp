#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, Q;
    cin >> N >> Q;

    string S;
    cin >> S;

    vector<int> l(Q);
    vector<int> r(Q);
    for (int i = 0; i < Q; i++) {
        cin >> l[i] >> r[i];
    }

    vector<int> dp(N, 0);
    for (int i = 0; i < N - 1; i++) {
        if (S[i] == 'A' && S[i + 1] == 'C') {
            if (i == 0) {
                dp[i] = 1;
            } else {
                dp[i] = dp[i - 1] + 1;
            }
        } else {
            if (i == 0) {
                dp[i] = 0;
            } else {
                dp[i] = dp[i - 1];
            }
        }
    }
    dp[N - 1] = dp[N - 2];

    for (int i = 0; i < Q; i++) {
        int count = 0;
        count = dp[r[i] - 1];
        // cout << dp[r[i] - 1] << " " << dp[l[i] - 2] << endl;
        if (r[i] != N) {
            if (S[r[i] - 1] == 'A' && S[r[i]] == 'C') {
                count--;
            }
        }
        // if (l[i] != 1) {
        //     if (S[l[i] - 1] == 'A' && S[l[i]] == 'C') {
        //         count--;
        //     }
        // }
        count -= dp[l[i] - 2];
        cout << count << endl;
    }

    return 0;
}
