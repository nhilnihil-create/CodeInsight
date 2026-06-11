#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    ll N;
    cin >> N;
    if (N % 2 == 1) {
        cout << N * 2 << endl;
    } else {
        cout << N  << endl;
    }
}
