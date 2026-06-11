#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    int n = s.size();
    string k = "keyence";
    bool ans = false;
    for (int i=0; i<=n-7; ++i) {
        string ps = s.substr(i, 7);
        if (ps == k) ans = true;
    }
    for (int i=0; i<n; ++i) {
        for (int j=i; j<n; ++j) {
            string sf, sb;
            sf = s.substr(0, i);
            sb = s.substr(j, n-1+j);
            if (sf+sb == k) ans = true;
        }
    }
    cout << (ans ? "YES" : "NO") << endl;
}