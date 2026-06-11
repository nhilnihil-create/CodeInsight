#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i<(n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
using ll = long long;

int N;
string S[310];
string SS[310];

bool check(int A) {
    rep(i, N) {
        rep(j, N) {
            int ni = (i + A) % N;
            SS[ni][j] = S[i][j];
        }
    }

    rep(i, N) {
        rep(j, N) {
            if (SS[i][j] != SS[j][i]) return false;
        }
    }
    return true;
}

int main() {
    cin >> N;
    rep(i, N) {
        string s;
        cin >> s;
        S[i] = SS[i] = s;
    }
    int ans = 0;
    rep(A, N) {
        if (check(A)) ans += N;
    }

    cout << ans << endl;
}
