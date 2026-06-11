#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int n; cin >> n;
    string s; cin >> s;

    ll ans = 0;
    map<pair<string, string>, ll> m;
    for(int S = 0; S < (1 << n); ++S) {
        string s1, s2;
        for(int i = 0; i < n; ++i) {
            if(S & (1 << i)) s1 += s[i];
            else             s2 += s[i];
        }
        m[make_pair(s1, s2)] += 1;
    }
    for(int S = 0; S < (1 << n); ++S) {
        string s1, s2;
        for(int i = 0; i < n; ++i) {
            if(S & (1 << i)) s1 += s[i + n];
            else             s2 += s[i + n];
        }
        reverse(begin(s1), end(s1));
        reverse(begin(s2), end(s2));
        ans += m[make_pair(s1, s2)];
    }
    cout << ans << endl;
}