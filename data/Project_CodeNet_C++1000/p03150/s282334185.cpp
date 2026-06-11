#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i < (int)(n); i++)
using ull = unsigned long long;
using ll = long long;

int main() {
    string S;
    cin >> S;

    bool ok = false;
    for (int i=0; i<S.size(); i++) {
        for (int j=0; j<S.size()-i; j++) {
            if (S.substr(0, i) + S.substr(i+j) == "keyence") ok = true;
        }
    }

    if (ok) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}

