#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const ll mod = 1000000007;

int main() {
    ll n;
    string s;
    cin >> n >> s;
    map<char, ll> mp;
    for (char c : s) mp[c]++;
    ll ans = 1;
    for (auto p : mp) {
        ans *= p.second + 1;
        ans %= mod;
    }
    cout << ans - 1 << endl;
}
