#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

#define MOD 1000000007

int main(void) {
    ll N, K;
    ll mini = LONG_MAX;
    vector<ll> X;
    vector<ll> D;
    cin >> N >> K;
    X.resize(N);
    for(ll i = 0;i < N;i++) cin >> X[i];
    for(ll i = K - 1;i < N;i++) {
        ll start = i - K + 1;
        ll current = X[i] - X[start];
        mini = min(mini, current + min(abs(X[start]), abs(X[i])));
    }
    cout << mini << endl;
    return 0;
}
