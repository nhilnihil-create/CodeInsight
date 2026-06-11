#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    ll K, A, B; cin >> K >> A >> B;
    ll cur = 1;
    ll mon = 0;
    while (K > 0) {
        if (cur < A && (K > A - cur)) {
            K -= A - cur;
            cur = A;
            continue;
        }
        if (cur >= A && B - A > 2 && K >= 2) {
            cur += (B - A);
            K -= 2;
            continue;
        }
        cur += K;
        K = 0;
    }
    cout << cur << endl;
}
