#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int M, K;
    cin >> M >> K;
    if (M <= 1) {
        if (K == 0) {
            cout << 0 << " " << 0 << " ";
            if (M == 1) cout << 1 << " " << 1 << endl;
        } else
            cout << -1 << endl;
        return 0;
    }
    if (K < (1 << M)) {
        for (int i = 0; i < (1 << M); i++) {
            if (i == K) continue;
            cout << i << " ";
        }
        cout << K << " ";
        for (int i = (1 << M) - 1; i >= 0; i--) {
            if (i == K) continue;
            cout << i << " ";
        }
        cout << K << endl;
    } else
        cout << -1 << endl;
    return 0;
}