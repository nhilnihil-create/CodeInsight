/**
 *    author:  FromDihPout
 *    created: 2020-08-12
**/

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int q;
    cin >> q;
    vector<int> l(q), r(q);
    int high = 0;
    for (int i = 0; i < q; i++) {
        cin >> l[i] >> r[i];
        high = max(high, r[i]);
    }
    
    vector<bool> comp(high + 1);
    comp[0] = true; comp[1] = true;
    for (int i = 2; i <= high; i++) {
        if (!comp[i]) {
            for (int j = i + i; j <= high; j += i) {
                comp[j] = true;
            }
        }
    }
    
    vector<int> cnt(high + 1);
    cnt[0] = 0;
    for (int i = 1; i <= high; i++) {
        cnt[i] = cnt[i-1];
        if (!comp[i] && !comp[(i + 1) / 2]) {
            cnt[i]++;
        }
    }

    for (int i = 0; i < q; i++) {
        cout << cnt[r[i]] - cnt[l[i] - 1] << '\n';
    }
    return 0;
}