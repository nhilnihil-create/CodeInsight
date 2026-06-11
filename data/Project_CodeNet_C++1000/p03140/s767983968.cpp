#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    ll N;
    vector<string> S(3);
    cin >> N >> S[0] >> S[1] >> S[2];
    ll ans = 0;
    for ( int i = 0; i < N; i++ ) {
        set<char> c;
        for ( int j = 0; j < 3; j++ ) {
            c.insert(S[j][i]);
        }
        ans += c.size() - 1;
    }
    return ans;
}

int main() {
    auto ans = solve();
    cout << ans << "\n";
    return 0;
}