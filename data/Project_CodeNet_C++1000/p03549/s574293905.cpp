#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    int ans;
    ans = ((N - M) * 100 + M * 1900);
    for (int i = 0; i < M; i++)
    {
        ans *= 2;
    }
    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}