#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

typedef long long ll;

int solve() {
    int N, D;
    cin >> N;
    vector<int> c(13, 0);
    rep(i, N) {
        cin >> D;
        if (D == 0) return 0;
        c[D]++;
        if (c[D] == 3) return 0;
        if (D == 12 && c[D] == 2) return 0;
    }
    int ans = 0;
    rep(i, 1 << 11) {
        int d = 0, s = 24;
        for (int j = 1; j < 12; j++) {
            d++;
            if (c[j] == 0) continue;
            if (c[j] == 1 && ((i >> (j - 1)) & 1) == 0) continue;
            s = min(s, d);
            d = 0;
        }
        d++;
        if (c[12] == 1) {
            s = min(s, d);
            d = 0;
        }
        for (int j = 13; j < 24; j++) {
            d++;
            if (c[24 - j] == 0) continue;
            if (c[24 - j] == 1 && ((i >> (23 - j)) & 1) == 1) continue;
            s = min(s, d);
            d = 0;
        }
        d++;
        s = min(s, d);
        ans = max(ans, s);
    }
    return ans;
}

int main() {
    cout << solve() << endl;
}