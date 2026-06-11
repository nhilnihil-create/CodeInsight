// 7/4
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main() {
    int N;
    cin >> N;
    vector<int> h(N);
    rep(i, N) cin >> h[i];

    int res = 0;
    int bar = 0;
    rep(i, N) {
        if (bar < h[i]) {
            res += (h[i] - bar);
            bar = h[i];
        } else {
            bar = h[i];
        }
    }
    cout << res << endl;
}