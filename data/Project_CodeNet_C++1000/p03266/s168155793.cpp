#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, K; cin >> N >> K;
    if (K % 2 == 0) {
        ll ans =(N / K) * (N / K) * (N / K);
        if (N >= K / 2) ans += ((N - K/2) / K + 1) * ((N - K/2) / K + 1) * ((N - K/2) / K + 1);
        cout << ans<< endl;
    } else {
        cout << (N / K) * (N / K) * (N / K)  << endl;
    }
}
