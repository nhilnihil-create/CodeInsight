#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    string S;
    cin >> S;
    int n = S.size();
    int bs = 0;
    map<int,int> mn;
    mn[0] = 0;
    int f;
    for ( int i = 0; i < n; i++ ) {
        int b = 1 << (S[i]-'a');
        bs ^= b;
        f = 1e6;
        for ( int j = -1; j < 26; j++ ) {
            int bb = j < 0 ? 0 : (1 << j);
            if ( mn.count(bs ^ bb) > 0 ) {
                f = min(f, mn[bs^bb] + 1);
            }
        }
        if ( mn.count(bs) > 0 ) {
            mn[bs] = min(mn[bs], f);
        } else {
            mn[bs] = f;
        }
    }
    ll ans = f;
    return ans;
}

int main() {
    auto ans = solve();
    cout << ans << "\n";
    return 0;
}