#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int t[110000], x[110000], y[110000];
    t[0] = 0;
    x[0] = 0;
    y[0] = 0;
    for (int i = 1; i < n+1; ++i) cin >> t[i] >> x [i] >> y[i];
    bool ok = true;
    
    for (int i = 0; i < n; ++i) {
        int dt = t[i+1] - t[i];
        int p_diff = abs(x[i+1] - x[i]) + abs(y[i+1] - y[i]);
        if (dt < p_diff) {
            ok = false;
            break;
        }
        if (dt % 2 != p_diff % 2) {
            ok = false;
            break;
        }
    }

    if (ok == true) cout << "Yes" << endl;
    else cout << "No" << endl;
}