#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
ll MOD = 1e9 + 7;

int N, A, B, C;
vector<int> l;

int dfs(int cur, int a, int b, int c) {
    if (cur == N) {
        if (min(a, min(b, c)) > 0) {
            return abs(A - a) + abs(B - b) + abs(C - c) - 30;
        } else {
            return 1e9;
        }
    }
    // cout << cur << endl;
    int ret0 = dfs(cur + 1, a, b, c);
    int ret1 = dfs(cur + 1, a + l[cur], b, c) + 10;
    int ret2 = dfs(cur + 1, a, b + l[cur], c) + 10;
    int ret3 = dfs(cur + 1, a, b, c + l[cur]) + 10;
    return min(ret0, min(ret1, min(ret2, ret3)));
}

int main() {
    cin >> N >> A >> B >> C;
    l.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> l[i];
    }
    cout << dfs(0, 0, 0, 0) << endl;
    return 0;
}