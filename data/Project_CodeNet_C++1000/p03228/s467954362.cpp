#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

using ll = long long;

int main() {
    int A, B, K;
    cin >> A >> B >> K;
    rep(i, K / 2) {
        if (A % 2) A--;
        A /= 2;
        B += A;
        if (B % 2) B--;
        B /= 2;
        A += B;
    }
    if (K % 2) {
        if (A % 2) A--;
        A /= 2;
        B += A;
    }
    cout << A << " " << B << "\n";
}