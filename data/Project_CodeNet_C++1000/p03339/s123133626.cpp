#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ALL(vec) vec.begin(), vec.end()
#define rALL(vec) vec.rbegin(), vec.rend()
using namespace std;
using ll = long long;

int main() {
    int N;
    string S;
    cin >> N >> S;
    vector<int> W(N, 0);
    vector<int> E(N, 0);
    rep(i, N) {
            W[i] = (i == 0 ? 0 : W[i - 1]) + (S[i] == 'W' ? 1 : 0);
            E[N - 1 - i] = (i == 0 ? 0 : E[N - 1 - (i - 1)]) + (S[N - 1 - i] == 'E' ? 1 : 0);
    }
    int ans = 1e6;
    rep(i, N) {
        ans = min(ans, W[i] + E[i]);
    }
    cout << ans - 1 << endl;
    return 0;
}