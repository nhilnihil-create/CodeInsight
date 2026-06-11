#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int m500, m100, m50, x;
    cin >> m500 >> m100 >> m50 >> x;
    int ans = 0;
    for (int c500 = min(x / 500, m500); c500 >= 0; c500--) {
        int r500 = x - 500 * c500;
        for (int c100 = min(r500 / 100, m100); c100 >= 0; c100--) {
            int r100 = r500 - 100 * c100;
            for (int c50 = min(r100 / 50, m50); c50 >= 0; c50--) {
                int r50 = r100 - 50 * c50;
                if (r50 == 0) {
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}