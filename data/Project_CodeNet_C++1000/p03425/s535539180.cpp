//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()

int main() {
    int n;
    cin >> n;
    vector<ll> cnt(5);
    rep(i, n) {
        string s;
        cin >> s;
        char c = s[0];
        if (c == 'M') cnt[0]++;
        if (c == 'A') cnt[1]++;
        if (c == 'R') cnt[2]++;
        if (c == 'C') cnt[3]++;
        if (c == 'H') cnt[4]++;
    }

    ll ans = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = i+1; j < 5; j++) {
            for (int k = j+1; k < 5; k++) {
                ans += cnt[i]*cnt[j]*cnt[k];
            }
        }
    }
    cout << ans << endl;
    return 0;
}