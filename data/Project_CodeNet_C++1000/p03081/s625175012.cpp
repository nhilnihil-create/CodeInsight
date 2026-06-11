#include <bits/stdc++.h>
using namespace std;
#define rep(i, m, n) for (int i = m; i < n; ++i)

int N, Q;
string S;
char t[202020], d[202020];

int bs(int x) {
    rep(i, 0, Q) {
        if(S[x] == t[i]) {
            if(d[i] == 'L') x--;
            else x++;
        }
        if(x < 0) return 1;
        else if(x >= N) return 2;
    }
    return 0;
}

int main() {
    cin >> N >> Q >> S;
    rep(i, 0, Q) cin >> t[i] >> d[i];
    int l = -1, r = N;
    while(r - l > 1) {
        int mid = (l + r) / 2;
        if(bs(mid) == 1) l = mid;
        else r = mid;
    }
    int l2 = -1, r2 = N;
    while(r2 - l2 > 1) {
        int mid = (l2 + r2) / 2;
        if(bs(mid) == 2) r2 = mid;
        else l2 = mid;
    }
    cout << r2 - l - 1 << endl;
    return 0;
}
