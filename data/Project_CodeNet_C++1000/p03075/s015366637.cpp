#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    vector<int> N(5);
    rep(i,5) cin >> N.at(i);
    int K; cin >> K;
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (abs(N[j] - N[i]) > K) {
                cout << ":(" << endl;
                return 0;
            }
        }
    }
    cout << "Yay!" << endl;
}