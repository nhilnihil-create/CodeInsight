#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<bool>> b(m, vector<bool>(n, false));
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;

        for (int j = 0; j < k; j++) {
            int a;
            cin >> a;

            b.at(--a).at(i) = true;
        }
    }

    int cnt = 0;
    for (const auto &_b : b) {
        bool f = true;

        for (const auto &__b : _b)
            if (!__b) {
                f = false;
                break;
            }

        if (f)
            cnt++;
    }

    cout << cnt << endl;
}