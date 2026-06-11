#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;

int main() {
    int N;
    cin >> N;

    ll prev2 = 2, prev = 1, L; // 2つ前の値を持たせる
    for (int i = 2; i <= N; i++) {
        L = prev2 + prev;
        prev2 = prev;
        prev = L;
    }

    if (N == 1) {
        cout << 1 << endl;
    } else {
        cout << L << endl;
    }

    return 0;
}
