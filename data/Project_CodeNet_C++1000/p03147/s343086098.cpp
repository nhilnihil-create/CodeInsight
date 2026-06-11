#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int h[100];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> h[i];

    int ans = 0;
    while (true) {
        int tmp = 0;
        for (int i = 0; i < n; i++) {
            if (h[i] > 0) {
                tmp++;
                while (i < n && h[i] > 0) {
                    h[i]--;
                    i++;
                }
            }
        }
        if (tmp == 0) break;
        ans += tmp;
    }

    cout << ans << endl;
}