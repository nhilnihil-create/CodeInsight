#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int N, K;
    cin >> N >> K;
    vector<long long> v;
    for (int i = 0; i < N; i++) {
        long long val;
        cin >> val;
        v.push_back(val);
    }
    long long ans = 0;
    for (int l = 0; l <= min(N, K); l++) {
        for (int r = 0; r + l <= min(N, K); r++) {
            priority_queue<long long, vector<long long>, greater<long long>> pq;
            for (int i = 0; i < l; i++) {
                pq.push(v[i]);
            }
            for (int i = 0; i < r; i++) {
                pq.push(v[v.size() - 1 - i]);
            }
            int pop_cnt = min((r + l), K - (r + l));
            for (int i = 0; i < pop_cnt; i++) {
                long long top = pq.top();
                if (top >= 0) break;
                pq.pop();
            }

            long long sum = 0;
            while (!pq.empty()) {
                sum += pq.top();
                pq.pop();
            }
            ans = max(ans, sum);
        }
    }
    cout << ans << endl;
    return 0;
}