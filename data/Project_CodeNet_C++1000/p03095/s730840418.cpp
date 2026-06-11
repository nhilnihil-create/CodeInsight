#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repl(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define rep2l(i, s, n) for (ll i = (ll)(s); i < (ll)n; i++)

int main() {
    ll N;
    string S;
    cin >> N >> S;
    vector<ll> count(26, 0);
    rep(i, N) {
        char s = S[i];
        int num = (int)(s-'a');
        count[num]++;
    }
    ll ans = 1;
    rep(i, 26) {
        ans *= (count[i]+1);
        ans %= 1000000007;
    }
    if (ans == 0) {
        cout << 1000000006 << endl;
    }
    else {
        cout << ans-1 << endl;
    }
}