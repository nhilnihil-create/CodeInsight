#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;

typedef long long ll;

ll N, K;

int main() {
    cin >> N >> K;

    if (K % 2 == 0) {
        // mod K が 0
        ll tmp1 = N / K;

        // mod K が K / 2
        ll tmp2 = N * 2 / K;
        // K の倍数を引く
        tmp2 -= tmp1;

        cout << tmp1 * tmp1 * tmp1 + tmp2 * tmp2 * tmp2 << endl;
    } else {
        ll tmp = N / K;
        cout << tmp * tmp * tmp << endl;
    }
}