#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

using ll = long long;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    if (s[0] == '0' || s[n - 1] == '1') {
        cout << -1 << endl;
        return 0;
    }
    rep(i, n / 2) {
        if (s[i] != s[n - 2 - i]) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << "1 2" << endl;
    int root = 2;
    for (int i = 1; i * 2 < n; i++) {
        cout << root << " " << i + 2 << endl;
        if (s[i] == '1') root = i + 2;
    }
    for (int i = (n + 5) / 2; i <= n; i++) {
        cout << root << " " << i << endl;
    }
}