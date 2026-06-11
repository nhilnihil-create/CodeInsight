#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    vector<int> A(3);
    rep(i,3) cin >> A.at(i);
    sort(A.begin(),A.end());
    cout << A[2] * 10 + A[1] + A[0] << endl;

}