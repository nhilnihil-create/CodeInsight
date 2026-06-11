#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

using ll = long long;

int main() {
    ll N, MOD = 1e9 + 7, ans = 1;
    string S;
    cin >> N >> S;
    vector<int> A(26, 1);
    rep(i, N) {
        A[S[i] - 'a']++;
    }
    rep(i, 26) {
        ans = (ans * A[i]) % MOD;
    }
    cout << ans - 1 << "\n";
}