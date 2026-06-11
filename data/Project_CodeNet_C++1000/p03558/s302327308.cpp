#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

int main() {
    int K;
    cin >> K;
    int INF = K;
    deque<pii> deq;
    vector<int> dp(K, INF);
    dp[1] = 0;
    deq.push_back(pii(dp[1], 1));
    while (!deq.empty()) {
        int d, n;
        tie(d, n) = deq.front();
        deq.pop_front();
        if (dp[n] < d) {
            continue;
        }
        int n1 = (n + 1) % K;
        int n2 = (n * 10) % K;
        if (dp[n1] > d + 1) {
            dp[n1] = d + 1;
            deq.push_back(pii(dp[n1], n1));
        }
        if (dp[n2] > d) {
            dp[n2] = d;
            deq.push_front(pii(dp[n2], n2));
        }
    }
    int result = dp[0] + 1;
    cout << result << endl;
    return 0;
}