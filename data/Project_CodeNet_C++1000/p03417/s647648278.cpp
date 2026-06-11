#include <bits/stdc++.h>

#define rep(i, N) for (ll i = 0; i < N; i++)
#define rep1(i, N) for (ll i = 1; i <= N; i++)
#define MOD (int)1e9+7;

using ll = long long;
using namespace std;

int main() {
    ll N, M;
    cin >> N >> M;
    ll ans = 0;

    if(N == 1 || M == 1) {
        if(N == 1 && M == 1)
            ans = 1;
        else
            ans = max(M, N) - 2;
    } else if(N == 2 || M == 2) {
        ans = 0;
    } else {
        ans = (M - 2)*(N - 2);
    }
    
    cout << ans << "\n";
    return 0;
}
