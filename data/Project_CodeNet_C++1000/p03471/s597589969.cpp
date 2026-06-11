#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n, y;
    cin >> n >> y;
    int a = 10000;
    int b = 5000;
    int c = 1000;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n - i; j++) {
            int v = i * a;
            int w = j * b;
            int x = y - v - w;
            int res = v + w + x;
            if(x >= 0 && i + j + (x/c) == n) {
                if(res == y) {
                    cout << i << " " << j << " " << x/c << endl;
                    return;
                }
            }
        }
    }
    cout << "-1 -1 -1";

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
