#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

ll gcd(ll a, ll b) { 
    return b ? gcd(b, a%b) : a;
}

ll N; 
vector<ll> A;
int main() {
    cin >> N;
    A.resize(N);
    rep(i, N) cin >> A[i];

    vector<ll> left_gcd(N), right_gcd(N);
    left_gcd[0] = A[0];
    right_gcd[N - 1] = A[N - 1];

    for (int i = 1; i < N; i++) {
        left_gcd[i] = gcd(left_gcd[i - 1], A[i]);
    }
    // rep(i, N) {
    //     cout << left_gcd[i] << " ";
    // }
    // cout << endl;
    for (int i = N - 2; i >= 0; i--) {
        right_gcd[i] = gcd(right_gcd[i + 1], A[i]);
    }
    // rep(i, N) {
    //     cout << right_gcd[i] << " ";
    // }
    ll ans = 0;
    rep(i, N) {
        if (i == 0) {
            ans = max(ans, right_gcd[i + 1]);
        } else if (i == N - 1) {
            ans = max(ans, left_gcd[i - 1]);
        } else {
            ll tmp = gcd(left_gcd[i - 1], right_gcd[i + 1]);
            ans = max(ans, tmp);
        }
    }
    cout << ans << endl;
}