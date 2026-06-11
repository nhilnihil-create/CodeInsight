#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    string S;
    int W;
    cin >> S >> W;
    string ans;
    for ( int i = 0; i < S.size(); i+=W ) {
        ans.push_back(S[i]);
    }
    cout << ans << "\n";
    return 0;
}

int main() {
    solve();
    return 0;
}