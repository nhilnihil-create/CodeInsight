#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

int main() {
    int n, m;
    map<int, int> mp;

    bool ok;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        mp[a]++;
    }
    cin >> m;
    ok = true;
    for (int i = 0; i < m; i++) {
        int b;
        cin >> b;
        if (mp.count(b) && mp[b] > 0) {
            mp[b]--;
        } else {
            ok = false;
        }
    }

    if (ok) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
