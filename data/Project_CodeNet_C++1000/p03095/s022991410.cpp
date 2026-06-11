#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll MOD = 1000000007;

int main() {
    int n;
    string s;
    cin >> n >> s;

    vector<ll> X(26, 0);
    for (int i = 0; i < n; ++i) {
        int index = s[i] - 'a';
        X[index] += 1;
    }

    ll ans = 1;
    for (int i = 0; i < 26; ++i) {
        ans *= X[i] + 1;
        ans %= MOD;
    }
    --ans;
    cout << ans << endl;
}
