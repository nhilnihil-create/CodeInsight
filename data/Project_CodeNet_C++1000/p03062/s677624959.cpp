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
    vector<ll> A(N);
    ll cnt = 0;
    rep(i, N) {
        cin >> A[i];
        if (A[i] < 0)
            cnt++;
    }

    ll ans = 0;
    if (cnt % 2 == 0) {
        rep(i, N) { ans += abs(A[i]); }
    } else {
        ll mi = INF;
        rep(i, N) {
            mi = min(mi, abs(A[i]));
            ans += abs(A[i]);
        }

        ans -= (2 * abs(mi));
    }

    cout << ans << endl;
    return 0;
}