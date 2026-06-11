#include <bits/stdc++.h>
using namespace std;

const int N = 22;

int main() {
    int n;
    array<int, N> v, c;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    int ans = INT_MIN;
    for (int i = 0; i < (1 << n); i++) {
        int cur_v = 0, cur_c = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                cur_v += v[j];
                cur_c += c[j];
            }
        }
        ans = max(ans, cur_v - cur_c);
    }

    cout << ans << endl;
}

