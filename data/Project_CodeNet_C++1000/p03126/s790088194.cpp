#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n, m;
    cin >> n >> m;
    map<int, bool> mp;
    int fk;
    cin >> fk;
    for (int i = 0; i < fk; i++) {
        int fa;
        cin >> fa;
        mp[fa] = true;
    }
    for (int i = 1; i < n; i++) {
        int k;
        cin >> k;
        map<int, bool> kmp;
        for (int ki = 0; ki < k; ki++) {
            int a;
            cin >> a;
            if (mp.count(a) > 0) {
                kmp[a] = true;
            }
        }
        mp = kmp;
    }
    cout << mp.size() << endl;
    return 0;
}