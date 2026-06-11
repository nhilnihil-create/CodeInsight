#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using namespace std;
const int INF = 1e9;

int main() {
    int N;
    string S;
    cin >> N >> S;

    int cnt = 0;
    rep(i, N) if (S[i] == '.') cnt++;

    int ans = cnt;
    rep(i, N) {
        if (S[i] == '#')
            cnt++;
        else
            cnt--;

        ans = min(ans, cnt);
    }
    cout << ans << endl;

    return 0;
}