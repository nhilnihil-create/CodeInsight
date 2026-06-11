#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000
typedef pair<ll, ll> pll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;
    vector<ll> A(N);
    rep(i, N) { cin >> A[i]; }

    ll ans = INF;
    rep(i, N) {
        ll r = i;
        ll l = i + K - 1;
        if (l >= N)
            break;

        ll can1 = abs(A[r]) + abs(A[r] - A[l]);
        ll can2 = abs(A[l]) + abs(A[l] - A[r]);

        ans = min(ans, min(can1, can2));
    }

    cout << ans << endl;
}