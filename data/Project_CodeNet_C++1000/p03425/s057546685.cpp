#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

constexpr long long mod = 1000000007;

#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<string> s(n);

    rep(i, n) cin >> s[i];

    map<char, int> mp;
    mp['M'] = 0;
    mp['A'] = 1;
    mp['R'] = 2;
    mp['C'] = 3;
    mp['H'] = 4;

    vll c(5, 0);

    rep(i, n) {
        if (mp.count(s[i][0]))
            c[mp[s[i][0]]]++;
    }
    ll ans = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 4; j++) {
            for (int k = j + 1; k < 5; k++) {
                ans += c[i] * c[j] * c[k];
            }
        }
    }

    cout << ans << endl;
}