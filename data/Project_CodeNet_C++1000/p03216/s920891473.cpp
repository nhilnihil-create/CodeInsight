#include <bits/stdc++.h>
using namespace std;
const int dh[8] = {0, 1, 0, -1, -1, 1, 1, -1};
const int dw[8] = {1, 0, -1, 0, 1, 1, -1, -1};

inline void solve(int n, const string& s, int k) {
    long long d = 0, m = 0, dm = 0, dmc = 0;
    
    auto add = [&] (int i) {
        if (s[i] == 'D') d++;
        if (s[i] == 'M') m++, dm += d;
        if (s[i] == 'C') dmc += dm;
    };
    auto erase = [&] (int i) {
        if (s[i] == 'D') d--, dm -= m;
        if (s[i] == 'M') m--;
    };
    
    int l = 0;
    for (int r = 0; r < n; r++) {
        while (l < n && abs(l - r) < k) add(l++);
        erase(r);
    }
    
    cout << dmc << endl;
    return;
}


int main() {
    int n, q;
    string s;
    cin >> n >> s >> q;
    while (q--) {
        int k;
        cin >> k;
        solve(n, s, k);
    }
    return 0;
}