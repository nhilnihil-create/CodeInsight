#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    vector<ll> BA(N);
    ll sum = 0;
    rep(i, N) {
        ll B;
        cin >> B;
        A.at(i) = B;
        BA.at(i) = B - i;
        sum += B;
    }
    sort(BA.begin(), BA.end());
    int M = BA.at(N / 2);
    ll sum2 = 0;
    rep(i,N) {
        sum2 += abs(A.at(i) - (M + i));
    }
    printf("%ld\n", sum2);
}