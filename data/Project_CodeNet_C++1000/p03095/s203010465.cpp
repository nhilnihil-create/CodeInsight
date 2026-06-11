#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    const int mod = 1000000007;
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<ll> counter(26, 0);
    rep(i, n) {
        counter[s[i] - 'a']++;
    }
    ll ans = 1;
    rep(i, 26) {
        (ans *= counter[i] + 1) %= mod;
    }
    ans--;
    cout << ans << endl;
}