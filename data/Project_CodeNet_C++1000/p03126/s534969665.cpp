#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k, a;
    cin >> n >> m;

    vector<int> count(m,0);
    for (int i = 0; i < n; i++) {
        cin >> k;
        for (int i = 0; i < k; i++) {
            cin >> a;
            count[a-1] ++;
        }
    }

    int ans = 0;
    for (int i = 0; i < m; i++) {
        if (count[i] == n)
            ans ++;
    }

    cout << ans << endl;
}