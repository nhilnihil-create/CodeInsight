#include <bits/stdc++.h>
using namespace std;
#define rep(i, m, n) for (int i = m; i < n; ++i)

int main() {
    int N, Q;
    string S;
    cin >> N >> Q >> S;
    vector<char> t(Q), d(Q);
    rep(i, 0, Q) cin >> t[i] >> d[i];
    auto side = [&](int x) {
        rep(i, 0, Q) if(S[x] == t[i]) {
            if(d[i] == 'L') x--;
            else x++;
            if(x == -1) return -1;
            else if(x == N) return 1;
        }
        return 0;
    };
    int l = -1, r = N;
    while(r - l > 1) {
        int mid = (l + r) / 2;
        if(side(mid) == -1) l = mid;
        else r = mid;
    }
    int left = l;
    l = -1, r = N;
    while(r - l > 1) {
        int mid = (l + r) / 2;
        if(side(mid) == 1) r = mid;
        else l = mid;
    }
    int right = r;
    cout << right - left - 1 << endl;
    return 0;
}
