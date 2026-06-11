#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

ll gcd(ll a, ll b) {
    if(a % b == 0) {
        return b;
    } else {
        return gcd(b, a % b);
    }
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<ll> H(N);
    for(int i=0; i<N; i++) cin >> H[i];
    sort(H.begin(), H.end());
    ll min_h = 1e10;

    for(int i=0; i<N-K+1; i++) {
        min_h = min(min_h, abs(H[i] - H[i+K-1]));
    }
    cout << min_h << endl;
}