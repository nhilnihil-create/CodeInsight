#include <bits/stdc++.h>
typedef long long int LL;
typedef unsigned long long int ULL;
using namespace std;

// 插入此處
LL bs(LL A, LL B) {
    // [1, 2, ..., A-1] x [B+1, B+2, ...]
    // find max n st [1, 2, ... n] x [B+1, B+2, ..., B+n] is affordable
    // given n, the max is (B+n+1)^2 / 4
    LL lo = 1, hi = A;
    if (B+1 >= A*B)  return 0;
    while (lo < hi - 1) {  // [lo, hi)
        LL mid = (lo + hi) / 2;
        // cout << "mid " << mid << endl;
        LL t = B+mid+1;
        LL ma = max(1 * (B+mid+1-1), mid * (B+mid+1-mid));
        if (t/2 <= mid)  ma = max(ma, t/2 * (B+mid+1-t/2));
        if (ma >= A*B) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    return lo;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int Q; cin >> Q;
    while (Q--) {
        LL A, B; cin >> A >> B;
        LL l = bs(A, B);
        LL r = bs(B, A);
        // cout << l << ' ' << r << endl;
        cout << l + r + min(A-1-l, B-1-r) << endl;
    }
    return 0;
}
