#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
int main() {
    int m, k;
    cin >> m >> k;
    if (m == 1) {
        if (k == 0) {
            cout << 0 << " " << 0 << " " << 1 << " " << 1 << endl;
        }
        else {
            cout << -1 << endl;
        }
        return 0;
    }
    if (k > (1 << m) - 1) {
        cout << -1 << endl;
        return 0;
    }
    cout << k << " ";
    for (int i = 0; i < (1 << m); i++) {
        if (i != k) {
            cout << i << " ";
        }
    }
    cout << k << " ";
    for (int i = (1 << m) - 1; i >= 0; i--) {
        if (i != k) {
            cout << i << " ";
        }
    }
    
    return 0;
}