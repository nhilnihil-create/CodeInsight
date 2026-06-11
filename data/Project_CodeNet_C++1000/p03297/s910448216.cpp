#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

bool then(bool p, bool q) { return !p || q; }

int main() {
    lint T;
    cin >> T;

    while(T--) {
        lint A, B, C, D;
        cin >> A >> B >> C >> D;

        bool c1 = A >= B;
        bool c2 = B <= D;

        bool c31 = C < B;
        lint g = __gcd(B, D);
        // C < (A+kD)%B < B なるkが存在 <=> C-A%B < k'g < B-A%B なるk'が存在
        bool c32 = (B-A%B-1)-(B-A%B-1)%g > C-A%B;
        bool c3 = then(c31, !c32);
        cout << (c1&c2&c3 ? "Yes" : "No") << endl;
    }
}