#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i<(n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> P(N), Q(N);
    rep(i, N) cin >> P[i], P[i]--;
    rep(i, N) Q[P[i]] = i;

    int k = 0;
    int now = 1;
    rep(i, N - 1) {
        if (Q[i + 1] > Q[i]) {
            now++;
        } else {
            chmax(k, now);
            now = 1;
        }
    }
    chmax(k, now);

    int ans = N - k;
    cout << ans << endl;
}
