#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

void factor(int M, vector<int>& V) {
    for (int i = 1; i * i <= M; i++) {
        if (M % i == 0) {
            V.push_back(i);
            if (M / i != i) V.push_back(M/i);
        }
    }
}

int main() {
    int N, M; cin >> N >> M;
    vector<int> V;
    factor(M, V);
    sort(V.begin(), V.end());
    auto x = lower_bound(V.begin(), V.end(), M/N);
    if (x == V.end() ) {
        cout << V[V.size() - 1] << endl;
    } else if (*x == M/N) {
        cout << *x << endl;
    } else {
        cout << *prev(x) << endl;
    }
}