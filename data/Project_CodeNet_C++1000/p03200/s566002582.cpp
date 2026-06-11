#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string s;
    cin >> s;
    ll ans = 0;
    ll w = 0;
    for (ll i = s.size() - 1;i >= 0;--i) {
        if (s[i] == 'W')++w;
        else ans += w;
    }
    cout << ans << endl;
}