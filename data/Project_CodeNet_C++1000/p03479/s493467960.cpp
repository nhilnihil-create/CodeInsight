#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;
const ll C = 1e9+7;

int main() {
    ll X, Y;
    cin >> X >> Y;

    int a = X;
    for(int i=1; ; i++) {
        X *= 2;
        if(X > Y) {
            cout << i << endl;
            return 0;
        }
    }
}