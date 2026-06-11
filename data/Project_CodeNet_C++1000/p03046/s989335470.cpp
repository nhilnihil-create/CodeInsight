#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main () {
    ll M, K;
    cin >> M >> K;
    if (M == 1) {
        if (K == 0) {
            puts("0 0 1 1");
        }
        else {
            puts("-1");
        }
        return 0;
    }
    if (K < (1 << M)) {
        for (int i = 0; i < (1 << M); i++) {
            if (i == K) continue;
            cout << i << endl;
        }
        cout << K << endl;
        for (int i = (1 << M)-1; i >= 0; i--) {
            if (i == K) continue;
            cout << i << endl;
        }
        cout << K << endl;
    }
    else {
        puts("-1");
    }
}