#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;

const int INF = 1e9;

int main() {
    int N, K, Q;
    cin >> N >> K >> Q;
    vector<int> A(N + 2);
    rep(i, N) cin >> A[i + 1];
    int ans = INF;
    auto solve = [&](int x) -> int {
        priority_queue<int> que;
        vector<int> P;
        rep(i, N + 2) if(A[i] < x) P.push_back(i);
        rep(i, P.size() - 1) {
            priority_queue<int, vector<int>, greater<int>> tmp;
            for(int j = P[i] + 1; j < P[i + 1]; ++j) tmp.push(A[j]);
            while(tmp.size() >= K) que.push(tmp.top()), tmp.pop();
        }
        int mx = 0;
        if(que.size() < Q) return INF;
        while(que.size() > Q) que.pop();
        return que.top() - x;
    };
    for(int i = 1; i < N + 1; ++i) ans = min(ans, solve(A[i]));
    cout << ans << '\n';
    return 0;
}
