#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;


int N;
vector<ll> A, B;


void input() {
    cin >> N;
    A = B = vector<ll>(N);
    rep(i, N) cin >> A[i];
    rep(i, N) cin >> B[i];
}


int main() {
    input();
    vector<ll> p2{1};
    rep(i, 30) p2.push_back(p2[i] * 2);
    
    ll ans = 0;
    for (int i = 29; i >= 0; i--) {
        rep(j, N) {
            A[j] %= p2[i + 1];
            B[j] %= p2[i + 1];
        }
        sort(B.begin(), B.end());
        ll s = 0;
        for (ll a : A) {
            auto x = lower_bound(B.begin(), B.end(), p2[i] - a);
            auto y = lower_bound(B.begin(), B.end(), p2[i + 1] - a);
            auto z = lower_bound(B.begin(), B.end(), p2[i] + p2[i + 1] - a);
            // int v = (y - x) + (B.end() - z);
            // if (v > 0) printf("%d %d %d\n", i, a, y - B.begin());
            s += (y - x) + (B.end() - z);
        }
        ans += p2[i] * (s % 2);
    }

    cout << ans << endl;
}
