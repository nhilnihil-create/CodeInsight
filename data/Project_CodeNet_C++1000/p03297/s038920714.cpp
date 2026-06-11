#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

int main() {
    lint T;
    cin >> T;

    while(T--) {
        lint A, B, C, D;
        cin >> A >> B >> C >> D;

        bool c0 = (A >= B);
        bool c1 = (B <= D);
        lint G = __gcd(B, D);
        lint mx = B + A%G - G;
        bool c2 = (B <= C || mx <= C);

        cout << (c0 && c1 && c2 ? "Yes" : "No") << endl;
    }
}