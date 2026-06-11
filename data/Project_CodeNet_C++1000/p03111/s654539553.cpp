#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < (int)(n); i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
using ll = long long;

int N, A, B, C;
vector<int> L;

int dfs(int idx = 0, int a = 0, int b = 0, int c = 0) {
    if (idx == N) {
        if (a > 0 && b > 0 && c > 0) return abs(A - a) + abs(B - b) + abs(C - c) - 30;
        else return (1 << 30);
    }
    return min({
        dfs(idx + 1, a, b, c),
        dfs(idx + 1, a + L[idx], b, c) + 10,
        dfs(idx + 1, a, b + L[idx], c) + 10,
        dfs(idx + 1, a, b, c + L[idx]) + 10,
    });
}

int main() {
    cin >> N >> A >> B >> C;
    L.resize(N);
    REP(i, 0, N) cin >> L[i];
    cout << dfs() << endl;
    return 0;
}