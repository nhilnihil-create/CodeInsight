#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(ll i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(ll i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(ll i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define len(x) ((ll)(x).length())

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // std::ifstream in("input.txt");
    // std::cin.rdbuf(in.rdbuf());
    ll n;
    cin >> n;
    vector<ll> t(n, 0), v(n, 0);
    rep(i, n) cin >> t[i], t[i] *= 2;
    rep(i, n) cin >> v[i];
    ll tt = accumulate(all(t), 0LL);
    vector<double> speed(tt + 1, 0);
    ll idx = 0, sumt = 0;
    reps(i, 1, tt) {
        if (i > (sumt + t[idx])) {
            sumt += t[idx];
            idx++;
        }
        speed[i] = speed[i - 1] + 0.5;
        speed[i] = min(speed[i], (double)v[idx]);
    }
    speed[tt - 1] = 0.5;
    idx = n - 1, sumt = 0;
    rrep(i, tt - 1) {
        speed[i] = min(speed[i], speed[i + 1] + 0.5);
        speed[i] = min(speed[i], (double)v[idx]);
        if (i == (tt - sumt - t[idx])) {
            sumt += t[idx];
            idx--;
        }
    }
    // rep(i, tt) {
    //     printf("[%lld]%.5f%s", i, speed[i], (i == (tt - 1)) ? "\n" : " ");
    // }
    double ans = 0;
    rep(i, tt) {
        ans += (speed[i] + speed[i + 1]) * 0.5 / 2.0;
    }
    printf("%.10f\n", ans);
    return 0;
}
