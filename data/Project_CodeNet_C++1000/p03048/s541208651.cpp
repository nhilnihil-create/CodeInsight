#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

constexpr ll INF = ll(1e+18) + 1;

ll dist(ll a, ll b, ll c, ll d) {
    return abs(a-c) + abs(b-d);
}

int main() {
    int R, G, B, N;
    int ans = 0;

    cin >> R >> G >> B >> N;

    rep(i, N/R + 1) {
        rep (j, (N-i*R)/G + 1) {
            if ((N - (i*R+j*G))%B == 0) {ans++;}
        }
    }

    cout << ans << endl;
}
