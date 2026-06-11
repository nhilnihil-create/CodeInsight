#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ALL(vec) vec.begin(), vec.end()
#define rALL(vec) vec.rbegin(), vec.rend()
using namespace std;
using ll = long long;

int main() {
    string S;
    cin >> S;
    string keyence = "keyence";
    rep(i, S.size() - 1) {
        for (int j = i; j < S.size(); ++j) {
            string left = S.substr(0, i);
            string right = S.substr(j);
            if (keyence == left + right) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}