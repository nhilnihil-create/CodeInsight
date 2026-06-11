#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    vector<int> A(3);
    vector<int> D(3);
    rep(i,3) cin >> A[i];
    D[0] = abs(A[0] - A[1]);
    D[1] = abs(A[0] - A[2]);
    D[2] = abs(A[1] - A[2]);
    sort(D.begin(), D.end());
    cout << D[0] + D[1] << endl;
}
