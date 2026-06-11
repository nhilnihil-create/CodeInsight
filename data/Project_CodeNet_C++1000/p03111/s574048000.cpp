#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1LL << 60;
const ll MOD = 1000000007;

int N, A, B, C;
vector<int> L;

int dfs(int cnt, int a, int b, int c) {
    if (cnt == N) {
        if (a == 0 || b == 0 || c == 0) return 1000000010;
        return abs(a - A) + abs(b - B) + abs(c - C) - 30;
    }

    int sum0 = dfs(cnt + 1, a, b, c);
    int sum1 = dfs(cnt + 1, a + L[cnt], b, c) + 10;
    int sum2 = dfs(cnt + 1, a, b + L[cnt], c) + 10;
    int sum3 = dfs(cnt + 1, a, b, c + L[cnt]) + 10;

    int min1 = min(sum0, sum1);
    int min2 = min(sum2, sum3);
    int min3 = min(min1, min2);
    return min3;
}

int main() {
    cin >> N >> A >> B >> C;
    L.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> L[i];
    }

    cout << dfs(0, 0, 0, 0) << endl;
    return 0;
}