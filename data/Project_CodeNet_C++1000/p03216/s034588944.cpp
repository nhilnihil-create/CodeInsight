#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int q;
    cin >> q;
    while (q--) {
        int k;
        cin >> k;
        long long ans = 0;
        long long ds = 0, ms = 0, dms = 0;
        for (int i = 0; i < n; i++) {
            if (i >= k) {
                if (s[i - k] == 'D') ds--, dms -= ms;
                if (s[i - k] == 'M') ms--;
            }
            if (s[i] == 'D') ds++;
            if (s[i] == 'M') ms++, dms += ds;
            if (s[i] == 'C') ans += dms;
        }
        cout << ans << '\n';
    }
}