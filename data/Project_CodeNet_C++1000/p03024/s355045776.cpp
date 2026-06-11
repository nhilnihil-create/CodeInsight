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
    int cnt = 0;
    rep(i, S.size()) if (S[i] == 'x') cnt += 1;
    if (cnt > 7) cout << "NO" << endl;
    else cout <<"YES" << endl;
    return 0;
}