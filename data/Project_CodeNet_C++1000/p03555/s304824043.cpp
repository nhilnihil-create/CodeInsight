#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;

int main() {
    vector<char> C(6);
    rep(i, 6) cin >> C[i];
    if (C[0] == C[5] && C[1] == C[4] && C[2] == C[3]) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}