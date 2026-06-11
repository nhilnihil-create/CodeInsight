#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    ll N,K;
    cin >> N >> K;
    // Odd
    ll res = pow(N / K, 3LL);
    if (K % 2 == 0) {
        cout << (ll)pow((N + K / 2LL) / K, 3LL) + res << endl;
    } else {
        cout << res << endl;
    }
}
