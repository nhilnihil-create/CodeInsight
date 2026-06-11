#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

using ll = long long;

int main() {
    int N, ans = 0;
    cin >> N;
    vector<string> S(N * 2);
    rep(i, N) {
        cin >> S[i];
        S[i + N] = S[i];
    }
    rep(i, N) {
        bool f = true;
        rep(j, N) {
            rep(k, N) {
                if (S[i + j][k] != S[i + k][j]) f = false;
            }
        }
        if (f) ans += N;
    }
    cout << ans << endl;
}