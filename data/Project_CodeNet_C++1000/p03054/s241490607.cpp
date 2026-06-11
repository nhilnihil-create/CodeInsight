#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    int H, W, N, sr, sc;
    string S, T;
    cin >> H >> W >> N >> sr >> sc >> S >> T;
    int l = 1, r = W, u = 1, d = H;
    for (int i = N - 1; i >= 0; i--) {
        if (T[i] == 'L') r = min(W, r + 1);
        if (T[i] == 'R') l = max(1, l - 1);
        if (T[i] == 'U') d = min(H, d + 1);
        if (T[i] == 'D') u = max(1, u - 1);
        if (S[i] == 'L') l = min(W + 1, l + 1);
        if (S[i] == 'R') r = max(0, r - 1);
        if (S[i] == 'U') u = min(H + 1, u + 1);
        if (S[i] == 'D') d = max(0, d - 1);
        //cout << "l=" << l << " r=" << r << " u=" << u << " d=" << d << "\n";
        if (l > r || u > d) {
            cout << "NO\n";
            return 0;
        }
    }
    if (u <= sr && sr <= d && l <= sc && sc <= r) cout << "YES\n";
    else cout << "NO\n";
}