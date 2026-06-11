#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
using namespace std;
using ll = long long;

int main() {
    vector<char> tmp(3);
    rep(i, 3) cin >> tmp[i];
    set<char> S(tmp.begin(), tmp.end());
    if (S.size() == 3) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}