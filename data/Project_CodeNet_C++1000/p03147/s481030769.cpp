#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int h[100];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> h[i];

    int ans = 0;
    while (true) {
        if (*max_element(h, h + n) == 0) break;

        int i = 0;
        while (i < n) {
            if (h[i] == 0) i++;
            else {
                ans++;
                while (i < n && h[i] > 0) {
                    h[i]--;
                    i++;
                }
            }
        }
    }

    cout << ans << endl;
}
