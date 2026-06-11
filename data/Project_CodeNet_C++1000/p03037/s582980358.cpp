#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int N, M;
    cin >> N >> M;
    int left = 1, right = N;
    rep(i, M) {
        int l, r;
        cin >> l >> r;
        left = max(left, l);
        right = min(right, r);
    }
    int ans = max(0, right - left + 1);
    cout << ans << '\n';
    return 0;
}