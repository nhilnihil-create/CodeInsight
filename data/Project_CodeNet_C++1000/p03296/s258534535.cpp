#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ALL(vec) vec.begin(), vec.end()
#define rALL(vec) vec.rbegin(), vec.rend()
using namespace std;
using ll = long long;
// ------------------------------

int main() {
    int N;
    cin >> N;
    int before = 0;
    int ans = 0;
    rep(i, N) {
        int a;
        cin >> a;
        if (a == before) ans += 1, before = 0;
        else before = a;
    }
    cout << ans << endl;
    return 0;
}