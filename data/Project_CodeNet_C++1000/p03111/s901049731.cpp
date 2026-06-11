#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 1LL << 60;
const ll mod = 1e9 + 7;

int N, A, B, C;
int l[8];
int ans = inf;
void dfs(int depth, int a, int b, int c, int cost) {
    if(depth == N) {
        if(a && b && c) ans = min(ans, cost + abs(A - a) + abs(B - b) + abs(C - c));
    } else {
        dfs(depth + 1, a + l[depth], b, c, cost + 10);
        dfs(depth + 1, a, b + l[depth], c, cost + 10);
        dfs(depth + 1, a, b, c + l[depth], cost + 10);
        dfs(depth + 1, a, b, c, cost);
    }
}
int main() {
    cin >> N >> A >> B >> C;
    for(int i = 0; i < N; i++) cin >> l[i];
    dfs(0, 0, 0, 0, 0);
    cout << ans - 30 << "\n";
    return 0;
}