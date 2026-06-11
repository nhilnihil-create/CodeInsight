#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

ll A, B, C, K;

int main() {
    cin >> A >> B >> C >> K;

    if (A == B && B == C) {
        cout << 0 << endl;
        return 0;
    }

    if (abs(A - B) > 1e18) {
        cout << "Unfair" << endl;
        return 0;
    }

    if (K % 2 == 0) {
        cout << A - B << endl;
    } else {
        cout << B - A << endl;
    }
    // rep(i, K) {
    //     ll before_A = A, before_B = B, before_C = C;

    //     A = before_B + before_C;
    //     B = before_A + before_C;
    //     C = before_A + before_B;

    //     if (abs(A - B) > 1e18) {
    //         cout << "Unfair" << endl;
    //         return 0;
    //     }
    // }

    // cout << A - B << endl;
}