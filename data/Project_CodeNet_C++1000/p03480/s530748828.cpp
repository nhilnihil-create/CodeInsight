#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define is(a, b) a == b
#define sz(v) ll(v.size())

void solve(string S){
    vector<ll> v;
    rep(i, sz(S)-1) {
        if (S[i+1] != S[i]) {
            v.push_back(max(i+1, sz(S)-i-1));
        }
    }
    ll mn = sz(S);
    rep(i, sz(v)) {
        mn = min(mn, v[i]);
    }
    cout << mn << endl;
}

int main() {
    string S;
    cin >> S;
    solve(S);
    return 0;
}
