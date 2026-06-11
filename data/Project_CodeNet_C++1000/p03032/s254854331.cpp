#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using P = pair<int, int>;
using vec = vector<int>;
using mat = vector<vector<int>>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define endl "\n"

constexpr int MOD = 1000000007;
const int INF = 1 << 30;

int main() {
    int n, k;
    cin >> n >> k;
    vec v(n);
    rep(i, n) cin >> v[i];

    int res = 0;

    for (int a = 0; a <= min(n, k); a++) {
        for (int b = 0; a + b <= min(n, k); b++) {
            priority_queue<int, vec, greater<int>> que;
            int tres = 0;

            for (int i = 0; i < a; i++) que.push(v[i]);
            rep(i, b) que.push(v[n-1-i]);

            rep(i, k-a-b) if (!que.empty() && que.top() < 0) que.pop();

            while (!que.empty()) {
                tres += que.top();
                que.pop();
            }

            res = max(res, tres);
        }
    }

    cout << res << endl;
    return 0;
}