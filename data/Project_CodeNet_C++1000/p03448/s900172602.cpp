#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;

int main() {
    int A, B, C, X;
    cin >> A >> B >> C >> X;

    int count = 0;
    rep(i, A + 1) { // O(N^3) -> 50^3 -> 125000
        rep(j, B + 1) {
            rep(k, C + 1) {
                if (X == 500 * i + 100 * j + 50 * k) count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}
