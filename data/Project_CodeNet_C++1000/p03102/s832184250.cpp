#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, c;
    cin >> n >> m >> c;
    vector<int> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b.at(i);
    }
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a.at(i).at(j);
        }
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        int ans = 0;
        for (int j = 0; j < m; j++) {
            ans += a.at(i).at(j) * b.at(j);
        }
        if (ans + c > 0) {
            count++;
        }
    }

    cout << count << endl;
}