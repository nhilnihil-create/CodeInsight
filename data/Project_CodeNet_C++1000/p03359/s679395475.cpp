#include <bits/stdc++.h>
using namespace std;
int main () {
    int a, b;
    cin >> a >> b;
    int ans = 0;
    for (int i = 1; i <= 12; i++) {
        if (a == i) {
            if (i <= b) {
                ans++;
            }
            break;
        }
        ans++;
    }
    cout << ans << endl;
}