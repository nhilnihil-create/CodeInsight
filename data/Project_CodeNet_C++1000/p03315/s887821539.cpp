#include <bits/stdc++.h>
using namespace std;
#define rep(i, N) for (long long i = 0; i < N; i++)
using ll = long long;

void solve(std::string S) {
    ll ans = 0;
    rep(i, 4) {
        if (S[i] == '+') {
            ans++;
        } else {
            ans--;
        }
    }
    cout << ans << endl;
}

int main() {
    std::string S;
    std::cin >> S;
    solve(S);
    return 0;
}
