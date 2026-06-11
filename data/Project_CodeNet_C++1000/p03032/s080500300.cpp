#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < (int)(n); i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
using ll = long long;

int N, K;
vector<int> D;

int main() {
    cin >> N >> K;
    D.resize(N);
    REP(i, 0, N) cin >> D[i];
    
    vector<int> A(N + 1, 0), B(N + 1, 0);
    using pq = priority_queue<int, vector<int>, greater<int>>;
    vector<pq> AQ(N + 1), BQ(N + 1);
    REP(i, 0, N) {
        A[i + 1] += A[i] + D[i];
        B[i + 1] += B[i] + D[N - 1 - i];
        AQ[i + 1] = AQ[i];
        BQ[i + 1] = BQ[i];
        if (D[i] < 0) AQ[i + 1].push(D[i]);
        if (D[N - 1 - i] < 0) BQ[i + 1].push(D[N - 1 - i]);
    }

    int ans = 0;
    REP(a, 0, min(N, K) + 1) {
        REP(b, 0, min(N, K) + 1) {
            if (a + b > min(N, K)) continue;
            int rem = K - a - b, cur = A[a] + B[b];
            // cout << "# a : " << a << ", b : " << b << ", cur : " << cur << ", rem : " << rem << endl;
            if (rem > 0) {
                pq tmpa = AQ[a], tmpb = BQ[b];
                while (rem--) {
                    if (tmpa.empty() && tmpb.empty()) {
                        break;
                    } else if (tmpa.empty()) {
                        cur -= tmpb.top(); tmpb.pop();
                    } else if (tmpb.empty()) {
                        cur -= tmpa.top(); tmpa.pop();
                    } else {
                        if (tmpa.top() < tmpb.top()) {
                            cur -= tmpa.top(); tmpa.pop();
                        } else {
                            cur -= tmpb.top(); tmpb.pop();
                        }
                    }
                }
            }
            // cout << "--> cur : " << cur << endl;
            ans = max(ans, cur);
        }
    }
    cout << ans << endl;
    return 0;
}