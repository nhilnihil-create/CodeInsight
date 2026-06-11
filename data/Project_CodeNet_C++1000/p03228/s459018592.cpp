#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ALL(vec) vec.begin(), vec.end()
#define rALL(vec) vec.rbegin(), vec.rend()
using namespace std;
using ll = long long;

int main() {
    int A, B, K;
    cin >> A >> B >> K;
    rep(i, K) {
        if (i % 2 == 0) {
            if (A % 2 == 1) A -= 1;
            B += A / 2;
            A /= 2;
        } else {
            if (B % 2 == 1) B -= 1;
            A += B / 2;
            B /= 2;
        }
    }
    cout << A << " " << B << endl;
    return 0;
}