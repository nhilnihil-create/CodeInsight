#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ALL(vec) vec.begin(), vec.end()
#define rALL(vec) vec.rbegin(), vec.rend()
using namespace std;
using ll = long long;
// ------------------------------

int main() {
    string S;
    int w;
    cin >> S >> w;
    rep(i, S.size()) if (i % w == 0) cout << S[i];
    cout << endl;
    return 0;
}