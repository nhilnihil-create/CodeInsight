#include "bits/stdc++.h"

using namespace std;
using ull = unsigned long long;

int main() {
    ull X, Y;
    cin >> X >> Y;

    int ans = 0;
    while (X <= Y) {
        X <<= 1ULL;
        ++ans;
    }
    cout << ans << endl;
}