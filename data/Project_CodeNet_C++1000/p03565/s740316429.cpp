#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s, t;
    cin >> s >> t;
    int k = (int) t.size();
    int n = (int) s.size();
    bool ok = 0;
    int i = n - 1;
    while(i >= 0) {
        ok = 1;
        for (int j = 0; j < k; j++) {
            if(s[i + j - k + 1] != t[j]) {
                if(s[i + j - k + 1] != '?') {
                    ok = 0;
                    break;
                }
            }
        }
        if(ok) {
            for (int q = i, p = k - 1; p >= 0; q--, p--) {
                s[q] = t[p];
            }
            break;
        }
        i--;
    }
    if(ok) {
        int j = 0;
        while (j < n) {
            if(s[j]  == '?') {
                cout << 'a';
            }
            else {
                cout << s[j];
            }
            j++;
        }
    }
    else {
        cout << "UNRESTORABLE";
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
