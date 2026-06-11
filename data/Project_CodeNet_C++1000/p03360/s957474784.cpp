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
    int a, b, c, k;
    cin >> a >> b >> c >> k;

    priority_queue<int> que;
    que.push(a);
    que.push(b);
    que.push(c);

    rep(i, k) {
        int t = que.top();
        que.pop();
        t *= 2;
        que.push(t);
    }

    int res = 0;
    while (!que.empty()) {
        res += que.top();
        que.pop();
    }
    cout << res << endl;
    return 0;
}