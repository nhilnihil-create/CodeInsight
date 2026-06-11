#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    int N, K;
    cin >> N >> K;
    N -= K;
    if (N == 0) {
        cout << 1 << endl;
        return 0;
    }
    cout << N / (K - 1) + (N % (K - 1) != 0 ? 1 : 0) + 1<< endl;
}
