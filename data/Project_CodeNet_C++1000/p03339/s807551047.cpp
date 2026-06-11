#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T>
using vec = std::vector<T>;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    vec<int> W(N, 0);
    vec<int> E(N, 0);
    for (int i = 1; i < N; ++i) {
        W[i] = W[i - 1];
        if (S[i - 1] == 'W') ++W[i];
    }
    for (int i = N - 2; i >= 0; --i) {
        E[i] = E[i + 1];
        if (S[i + 1] == 'E') ++E[i];
    }
    int ans       = 1e9;
    rep(i, N) ans = min(ans, W[i] + E[i]);
    cout << ans << endl;
}