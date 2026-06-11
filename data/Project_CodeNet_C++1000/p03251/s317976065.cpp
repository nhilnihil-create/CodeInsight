#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    int N,M,X,Y;
    cin >> N >> M >> X >> Y;
    if (X >= Y) {
        cout << "War" << endl;
        return 0;
    }
    vector<int> A(N);
    rep(i,N) cin >> A.at(i);
    sort(A.begin(), A.end());
    vector<int> B(M);
    rep(i,M) cin >> B.at(i);
    sort(B.begin(), B.end());
    if (A[A.size() - 1] < B[0] && X < B[0] && Y > A[A.size() - 1]) {
        cout << "No War" << endl;
    } else {
        cout << "War" << endl;
    }
}
