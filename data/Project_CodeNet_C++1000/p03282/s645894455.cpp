#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using P = pair<int, int>;
using vec = vector<int>;
using mat = vector<vector<int>>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define endl "\n"

constexpr int MOD = 1000000007;
const int INF = 1 << 30;

int main() {
    string s;
    cin >> s;
    lint k;
    cin >> k;

    if (s[0] != '1') {
        cout << s[0] << endl;
    }
    else {
        int ceil = min(k, (lint)s.size());
        rep(i, ceil) {
            if (s[i] != '1') {
                cout << s[i] << endl;
                exit(0);
            }
        }
        cout << 1 << endl;
    }


    return 0;
}