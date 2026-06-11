#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

int main() {
    int Q; cin >> Q;
    while (Q--) {
        LL A, B; cin >> A >> B;
        LL ans = 0;
        LL sqrtAB;
        {
            LL l = 0, r = 1000000000;
            while (l + 1 < r) {
                LL m = (l + r) / 2;
                if (m * m < A * B) l = m; else r = m;
            }
            sqrtAB = l;
        }
        ans = sqrtAB * 2;
        if (sqrtAB * (sqrtAB + 1) >= A * B) ans--;
        if ((A * B - 1) / A != (A * B - 1) / (A + 1)) ans--;
        if ((A * B - 1) / B != (A * B - 1) / (B + 1)) ans--;
        cout << ans << endl;
    }
    return 0;
}