#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > rules(m, vector<int>(n));
    for (size_t i = 0; i < m; i++) {
        int k;
        cin >> k;
        for (size_t j = 0; j < k; j++) {
            int s;
            cin >> s;
            rules[i][s-1] = 1;
        }
    }
    vector<int> p(m);
    for (size_t i = 0; i < m; i++) cin >> p[i];

    int ans = 0;
    for (int i = 0; i < (1<<n); i++) {
        bool ok = true;
        for (int j = 0; j < m; j++) {
            int temp = 0;
            for (int k = 0; k < n; k++) {
                if ((i & (1<<k)) && rules[j][k]) temp++;
            }
            if (temp%2 != p[j]) ok = false;
        }
        if (ok) ans++;
    }

    cout << ans << endl;
    return 0;
}
