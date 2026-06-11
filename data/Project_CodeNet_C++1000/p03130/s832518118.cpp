#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define all(aaa) aaa.begin(), aaa.end()

set<pair<int, int>> st;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    

    for (int i = 0; i < 3; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        st.insert({x, y});
        st.insert({y, x});
    }

    int a[4];
    for (int i = 0; i < 4; i++) {
        a[i] = i;
    }

    do {
        bool ok = true;
        for (int i = 0; i + 1 < 4; i++) {
            if (!st.count({a[i], a[i + 1]})) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << "YES\n";
            return 0;
        }
    } while (next_permutation(a, a + 4));

    cout << "NO\n";

    return 0;
}