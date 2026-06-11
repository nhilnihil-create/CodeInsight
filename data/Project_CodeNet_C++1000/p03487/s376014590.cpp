#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repl(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define rep2l(i, s, n) for (ll i = (ll)(s); i < (ll)n; i++)

int main() {
    int N;
    cin >> N;
    ll ans = 0;
    map<ll, int> num;
    rep(i, N) {
        ll a;
        cin >> a;
        if (num.count(a)) {
            num[a]++;
        }
        else {
            num[a] = 1;
        }
    }
    for (auto p : num) {
        ll key = p.first;
        int count = p.second;
        if (key < count) {
            ans += count-key;
        }
        else if (count < key) {
            ans += count;
        }
    }
    cout << ans << endl;
}