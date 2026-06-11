#include "bits/stdc++.h"

using namespace std;

int main() {
    string S;
    cin >> S;
    int n = S.length();
    int l = 0, r = n - 1;
    int ans = 0;
    bool ok = true;
    while (l < r) {
        if (S[l] == S[r]) {
            ++l;
            --r;
        } else if (S[l] == 'x') {
            ans += 1;
            ++l;
        } else if (S[r] == 'x') {
            ans += 1;
            --r;
        } else {
            ok = false;
            break;
        }
    }

    if (ok) cout << ans << endl;
    else cout << -1 << endl;
}