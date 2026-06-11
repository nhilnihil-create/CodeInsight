#include <bits/stdc++.h>
using namespace std;
#define rep(i, N) for (long long i = 0; i < N; i++)
using ll = long long;

const string YES = "Yes";
const string NO = "No";

void solve(std::vector<std::vector<long long>> c) {
    vector<ll> a(3);
    vector<ll> b(3);
    rep(i, 3) { b[i] = c[0][i] - a[0]; }
    rep(i, 3) { a[i] = c[i][0] - b[0]; }
    rep(i, 3) {
        rep(j, 3) {
            if (c[i][j] != a[i] + b[j]) {
                cout << NO << endl;
                return;
            }
        }
    }
    cout << YES << endl;
}

int main() {
    std::vector<std::vector<long long>> c(3, std::vector<long long>(3));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%lld", &c[i][j]);
        }
    }
    solve(std::move(c));
    return 0;
}
