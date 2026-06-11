#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair< int, int >;

int main() {
    ll X, Y;
    cin >> X >> Y;

    int cnt = 0;
    while (X <= Y) {
        ++cnt;
        X *= 2LL;
    }

    cout << cnt << endl;
}