#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

using ll = long long;

int main() {
    int N, K, a;
    cin >> N >> K;
    vector<ll> s(N + 1, 0), v;
    rep(i, N) {
        cin >> a;
        s[i + 1] = s[i] + a;
    }
    rep(i, N) {
        for (int j = i + 1; j <= N; j++) {
            v.push_back(s[j] - s[i]);
        }
    }
    for (int i = 59; i >= 0; i--) {
        int c = 0;
        rep(j, v.size()) {
            if (v[j] & (1LL << i)) c++;
        }
        if (c < K) {
            rep(j, v.size()) v[j] = (v[j] | (1LL << i)) ^ (1LL << i); 
        } else {
            rep(j, v.size()) {
                if ((v[j] & (1LL << i)) == 0) v[j] = 0;
            }
        }
    }
    sort(v.begin(), v.end());
    /*
    rep(i, v.size()) {
        cout << v[i] << "\n";
    }
    */
    ll ans = v[v.size() - 1];
    rep(i, K) {
        ans = ans & v[v.size() - 1 - i];
    }
    cout << ans << "\n";
}