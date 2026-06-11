#include <bits/stdc++.h>
using namespace std;

#define REP(i, start, count) for(int i=(start); i<(int)(count); ++i)
#define rep(i, count) REP(i, 0, count)
#define ALLOF(c) (c).begin(), (c).end()

using ll = long long;
using ull = unsigned long long;
using veci = vector<int>;
using vecll = vector<ll>;
using vecull = vector<ull>;

int main(void) {
    ll N;
    string S;
    cin >> N >> S;

    ll w = 0, b = 0;
    ll bb = 0;
    ll ww = 0;
    bool first_w = true;
    rep(i, N) {
        if (S[i] == '#') {
            b++;
        }
        else {
            w++;
        }
    }

    ll lb = 0, lw = 0, rb = b, rw = w;
    ll ans = min(b, w);
    rep(i, N) {
        if (S[i] == '#') {
            lb++; rb--;
        }
        else {
            lw++; rw--;
        }

        ans = min(lb + rw, ans);
    }

    cout << ans << endl;
    return 0;
}
