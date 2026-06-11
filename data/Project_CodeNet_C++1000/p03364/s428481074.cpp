#include <bits/stdc++.h>

#define repd(i, a, b) for (ll i = (a); i < (b); i++)
#define repb(i, n) for (ll i = (n)-1; i >= 0; i--)
#define rep(i, n) repd(i, 0, n)

using namespace std;

using ll = long long;
using ul = unsigned long long;
using ld = long double;
ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    string s[n];
    rep(i, n) {
        cin >> s[i];
        s[i] += s[i];
    }
    ll ans = 0;
    rep(num, n) {
        bool result = true;
        rep(index_h, n) {
            rep(index_w, n) {
                if (s[index_h][index_w + num] != s[index_w][index_h + num]) {
                    result = false;
                }
            }
        }
        if (result) {
            ans++;
        }
    }
    cout << n * ans << endl;
    return 0;
}

