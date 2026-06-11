#include <bits/stdc++.h>

#define debug(x) cerr << #x << ": " << x << endl
#define debugArray(x, n)                                                       \
    for(long long hoge = 0; (hoge) < (n); ++(hoge))                            \
    cerr << #x << "[" << hoge << "]: " << x[hoge] << endl
using namespace std;

using ll = long long;
using ull = unsigned long long;
const ll INF = LLONG_MAX / 2;
const ll MOD = 1e9 + 7;

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int N;
    cin >> N;
    int Fbits[N];
    for(int i = 0; i < N; i++) {
        Fbits[i] = 0;
        for(int j = 0; j < 10; j++) {
            int F;
            cin >> F;
            Fbits[i] |= F << j;
        }
    }
    ll P[N][11];
    for(int i = 0; i < N; i++) {
        for(int j = 0; j <= 10; j++) {
            cin >> P[i][j];
        }
    }
    ll ans = -INF;
    for(int joi = 1; joi < (1 << 10); joi++) {
        ll a = 0;
        for(int i = 0; i < N; i++) {
            a += P[i][__builtin_popcount(Fbits[i] & joi)];
        }
        ans = max(ans, a);
    }
    cout << ans << endl;
    return 0;
}