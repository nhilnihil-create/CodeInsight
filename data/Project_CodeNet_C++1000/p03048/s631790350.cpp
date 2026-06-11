#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = 1'010'000'000'000'000'017LL;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int main() {
    // Atcoder
    // template: cpp
    ll R, G, B, N;
    cin >> R >> G >> B >> N;
    ll cnt = 0;

    rep(r, N + 1) {
        rep(g, N + 1) {
            ll Bb = N - r * R - g * G;
            if(Bb % B == 0 && Bb / B >= 0)
                cnt++;
        }
    }
    cout << cnt;
}
