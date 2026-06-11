#include <bits/stdc++.h>
using namespace std;

int main() {
    int X; cin >> X;
    int k = 1;
    if (X == 1) cout << 1 << endl;
    else {
        for (int i = 2; i < X; i++) {
            for (int j = 2; pow(i, j) <= X; j++) {
                int l = pow(i, j);
                k = max(k, l);
            }
        }
        cout << k << endl;
    }
}
