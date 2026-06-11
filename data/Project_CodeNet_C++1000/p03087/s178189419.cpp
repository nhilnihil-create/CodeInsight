#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int n, q;
    string s;
    cin >> n >> q >> s;

    int cnt[n] = {0};
    rep(i, n - 1) {
        if (s.substr(i, 2) == "AC") cnt[i + 1]++;
        cnt[i + 1] += cnt[i];
    }

    rep(i, q) {
        int l, r;
        cin >> l >> r;
        cout << cnt[r - 1] - cnt[l - 1] << endl;
    }

    return 0;
}
