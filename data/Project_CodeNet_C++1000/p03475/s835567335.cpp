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

    int N;
    cin >> N;
    vector<ll> C(N - 1), S(N - 1), F(N - 1);
    rep(i, N - 1) { cin >> C[i] >> S[i] >> F[i]; }

    for (int i = 0; i < N - 1; i++) {
        ll ans = S[i] + C[i];
        for (int j = i + 1; j < N - 1; j++) {
            if (ans >= S[j]) {
                if ((ans - S[j]) % F[j] == 0)
                    ans += C[j];
                else {
                    ll n = (ans - S[j]) / F[j] + 1;
                    ans += (S[j] + F[j] * n - ans) + C[j];
                }
            } else {
                ans = S[j];
                ans += C[j];
            }
        }

        cout << ans << endl;
    }

    cout << 0 << endl;
}