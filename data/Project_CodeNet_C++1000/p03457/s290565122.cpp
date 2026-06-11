#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;
const ll C = 1e9+7;

int main() {
    int N;
    cin >> N;
    int X = 0, Y = 0, T = 0;

    for(int i=0; i<N; i++) {
        int x, y, t;
        cin >> t >> x >> y;
        X = abs(x - X);
        Y = abs(y - Y);
        T = t - T;
        if((T < X + Y) || (T - X - Y) % 2 != 0) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}