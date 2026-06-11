#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

void solve() {
    int n;
    cin >> n;
    vector<int> seq(n);
    rep(i,n) {
        int p;
        cin >> p;
        p--;
        seq[p] = i;
    }

    int ans = 0;
    int cnt = 1;
    rep(i, n-1) {
        if (seq[i] < seq[i+1]) {
            cnt++;
        } else {
            ans = max(ans, cnt);
            cnt = 1;
        }
    }
    ans = max(ans, cnt);

    cout << n - ans << endl;
}

int main() {
    solve();
    return 0;
}
