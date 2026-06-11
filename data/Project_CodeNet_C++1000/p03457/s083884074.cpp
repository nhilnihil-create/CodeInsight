#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N = 0;
    cin >> N;
    int x, y, X, Y, t, T;
    x = y = t = 0;
    for(int i = 0; i < N; i++) {
        cin >> T >> X >> Y;
        if(abs(T - t) < abs(X - x) + abs(Y - y) || abs(X + x + Y + y + T + t)%2) {
            cout << "No" << endl;
            return 0;
        }
        t = T, x = X, y = Y;
    }

    cout << "Yes" << endl;

    return 0;
}