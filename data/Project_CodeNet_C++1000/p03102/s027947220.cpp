#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n, m, c;
    cin >> n >> m >> c;
    vector<int> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b.at(i);
    }
    int ans = 0;
    for (int x = 0; x < n; x++) {
        int sum = 0;
        for (int i = 0; i < m; i++) {
            int a;
            cin >> a;
            sum += a * b.at(i);
        }
        if (sum + c > 0) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}