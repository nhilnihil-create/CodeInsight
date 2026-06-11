#include <bits/stdc++.h>
using namespace std;
template<typename T> T GCD(T a, T b) { if (a % b == 0) { return b; } return(GCD(b, a % b)); }
void Yes() { cout << "Yes" << '\n'; return; }
void No () { cout << "No"  << '\n'; return; }

int main(){
    int Q; cin >> Q;
    while (Q--) {
        long long A, B, C, D;
        cin >> A >> B >> C >> D;
        if (A < B || D < B) { No(); continue; }
        if (B <= A && B <= D && B <= C) { Yes(); continue; }
        long long G = GCD(B, D), M = B - G + A % G;
        (M > C) ? No() : Yes();
    }
    return 0;
}