//#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>

using namespace std;


const int INF = 1e9;

int N, A, B, C;
vector<int> l;

int dfs(int i, int a, int b, int c) {
    if (i == N) {
        if (a == 0 || b == 0 || c == 0) return INF;
        return abs(A - a) + abs(B - b) + abs(C - c);
    }

    // not use
    int res = dfs(i+1, a, b, c);
    // A
    res = min(res, dfs(i+1, a + l[i], b, c) + (a == 0 ? 0: 10));
    // B
    res = min(res, dfs(i+1, a, b + l[i], c) + (b == 0 ? 0: 10));
    // C
    res = min(res, dfs(i+1, a, b, c + l[i]) + (c == 0 ? 0: 10));

    return res;
}


void solve() {
    cin >> N >> A >> B >> C;
    l.resize(N);
    for (int i = 0; i < N; i++) cin >> l[i];

    cout << dfs(0, 0, 0, 0) << endl;
}


int main() {
    solve();
    return 0;
}