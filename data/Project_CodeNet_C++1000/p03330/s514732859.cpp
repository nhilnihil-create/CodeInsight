#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, c;
    cin >> n >> c;
    vector<vector<int>> d(c, vector<int>(c));
    vector<vector<int>> a(n, vector<int>(n));
    map<int, int> mp[3];
    for (auto& v1 : d) for (auto& v2 : v1) { cin >> v2; }
    for (auto& v1 : a) for (auto& v2 : v1) { cin >> v2;v2--; }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mp[(i+j)%3][a[i][j]]++;
        }
    }
    
    long long ans = INT64_MAX;
    for (int c1 = 0; c1 < c; c1++) for (int c2 = 0; c2 < c; c2++) {
        if (c1 == c2) continue;
        for (int c3 = 0; c3 < c; c3++) if (c1 != c3 && c2 != c3) {
            int ch[3] = {c1, c2, c3};
            long long res = 0;
            for (int i = 0; i < 3; i++) {
                for (auto& e : mp[i]) res += (d[e.first][ch[i]] * e.second);
            }
            if (ans > res) ans = res;
        }
    }
    
    cout << ans << endl;
    return 0;
}