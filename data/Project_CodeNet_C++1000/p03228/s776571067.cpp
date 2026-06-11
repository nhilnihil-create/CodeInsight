#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P  = pair<int, int>;
int main() {
    ll a, b, k;
    cin >> a >> b >> k;
    for (int i = 0; i < k; ++i) {
        (i & 1 ? b : a) -= (i & 1 ? b : a) % 2;
        (i & 1 ? b : a) /= 2;
        (i & 1 ? a : b) += (i & 1 ? b : a);
    }
    cout << a << " " << b << endl;
}