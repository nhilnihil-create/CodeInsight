#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll A, B, K;
    cin >> A >> B >> K;
    for (int i = 0; i < K; i++) {
        if (i%2 == 0) {
            if (A%2 == 1) A--;
            B += A/2;
            A /= 2;
        } else {
            if (B%2 == 1) B--;
            A += B/2;
            B /= 2;
        }
    }
    cout << A << ' ' << B << endl;
    return 0;
}