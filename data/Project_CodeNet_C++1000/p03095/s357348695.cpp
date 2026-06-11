#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

using ll = long long;
const ll MOD = 1e9 + 7;

int main() {
    int N;
    string S;
    cin >> N >> S;
    vector<int> c(26, 1);
    rep(i, N) c[S[i] - 'a']++;
    ll ans = 1;
    rep(i, 26) ans = (ans * c[i]) % MOD;
    cout << (ans + MOD - 1) % MOD << endl;
}