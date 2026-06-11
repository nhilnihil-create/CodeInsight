#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

void solve() {
    string S;
    cin >> S;
    int c[] = { 0, 0, 0 }, n = S.size();
    rep(i, n) c[S[i] - 'a']++;
    string ans = "YES";
    rep(i, 3) if (c[i] > (n + 2) / 3) ans = "NO";
    cout << ans << endl;
    return;
}

int main() {
    solve();
}