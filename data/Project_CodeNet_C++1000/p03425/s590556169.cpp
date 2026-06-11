#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

ll nCr(ll n, ll r) {
    ll a = 1;
    for (ll i = 1; i <= r; i++)
    {
        a *= n--;
        a /= i;
    }
    return a;
}

int main() {
    int n;
    cin >> n;
    map<char, int> mp;
    mp['M'] = 0;
    mp['A'] = 0;
    mp['R'] = 0;
    mp['C'] = 0;
    mp['H'] = 0;
    rep(i, n) {
        string s;
        cin >> s;
        if (s[0] == 'M') mp[s[0]]++;
        else if (s[0] == 'A') mp[s[0]]++;
        else if (s[0] == 'R') mp[s[0]]++;
        else if (s[0] == 'C') mp[s[0]]++;
        else if (s[0] == 'H') mp[s[0]]++;
    }
    int m, a, r, c, h, cnt;
    m = mp.at('M');
    a = mp.at('A');
    r = mp.at('R');
    c = mp.at('C');
    h = mp.at('H');
    cnt = m + a + r + c + h;
    
    ll ans;
    ans = nCr(cnt, 3);

    if (m > 1) {
        ans -= nCr(m, 2) * (cnt - m) + nCr(m, 3);
    }
    if (a > 1) {
        ans -= nCr(a, 2) * (cnt - a) + nCr(a, 3);
    }
    if (r > 1) {
        ans -= nCr(r, 2) * (cnt - r) + nCr(r, 3);
    }
    if (c > 1) {
        ans -= nCr(c, 2) * (cnt - c) + nCr(c, 3);
    }
    if (h > 1) {
        ans -= nCr(h, 2) * (cnt - h) + nCr(h, 3);
    }
    cout << ans << endl;
    return 0;
}