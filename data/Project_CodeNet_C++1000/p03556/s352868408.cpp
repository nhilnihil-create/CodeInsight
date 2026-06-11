#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    int ans = 0;
    rep(i, N + 1) {
        if (i*i > N) break;
        ans = max(i*i, ans);
    }
    cout << ans << endl;
    return 0;
}