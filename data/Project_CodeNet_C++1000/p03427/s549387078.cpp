#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ALL(vec) vec.begin(), vec.end()
#define rALL(vec) vec.rbegin(), vec.rend()
using namespace std;
using ll = long long;
// ------------------------------

int main() {
    string N;
    cin >> N;
    int ans = 0;
    int flag = false;
    rep(i, N.size() - 1) {
        if (N[i + 1] != '9') flag = true;
        ans += 9;
    }
    int tmp;
    if (flag) {
        tmp = N[0] - '1';
    } else {
        tmp = N[0] - '0';
    }
    ans += tmp;
    cout << ans << endl;
    return 0;
}