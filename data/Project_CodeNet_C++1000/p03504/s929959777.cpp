#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, C;
    cin >> N >> C;
    vector<int> s(N), t(N), c(N);
    vector<vector<ll>> A(C, vector<ll>(pow(10, 5) + 10));
    vector<ll> B(pow(10, 5) + 10);
    rep(i, N) {
        cin >> s[i] >> t[i] >> c[i];
        c[i]--, s[i]--, t[i]--;
        A[c[i]][s[i]]++;
        A[c[i]][t[i]]--;
    }

    ll ans = 0;

    rep(i, pow(10, 5) + 9) {
        rep(j, C) {
            if (A[j][i] == 1)
                B[i]++;
            if (A[j][i] == -1)
                B[i + 1]--;
        }
    }

    rep(i, B.size() - 1) {
        B[i + 1] += B[i];
        ans = max(ans, B[i + 1]);
    }

    cout << ans << endl;
}