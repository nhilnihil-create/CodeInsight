#include <bits/stdc++.h>
using namespace std;
typedef long long Int;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n, q; cin >> n >> q;
    string s; cin >> s;
    vector<int> l(q), r(q);
    rep(i, q) {
        cin >> l[i] >> r[i];
        l[i]--;
        r[i]--;
    }
    vector<int> cnt(n);
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == 'C' && s[i-1] == 'A') {
            cnt[i] = cnt[i-1] + 1;
        }
        else {
            cnt[i] = cnt[i-1];
        }
    }
    rep(i, q) {
        cout << cnt[r[i]] - cnt[max(l[i], 0)] << endl;
    }
}
