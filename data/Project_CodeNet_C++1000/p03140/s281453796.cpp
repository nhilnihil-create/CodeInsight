#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ALL(vec) vec.begin(), vec.end()
#define rALL(vec) vec.rbegin(), vec.rend()
using namespace std;
using ll = long long;

int main() {
    int N;
    string A, B, C;
    cin >> N >> A >> B >> C;
    int ans = 0;
    rep(i, N) {
        set<char> S = {A[i], B[i], C[i]};
        ans += S.size() - 1;
    }
    cout << ans << endl;
    return 0;
}