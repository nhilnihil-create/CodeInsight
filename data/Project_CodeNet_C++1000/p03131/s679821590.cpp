#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll K, A, B;
    cin >> K >> A >> B;
    if(A + 2 < B) {
        ll ans = A;
        K -= A - 1;
        ans += (K/2)*(B - A) + K%2;
        cout << ans << endl;
    } else {
        cout << K + 1 << endl;
    }

    return 0;
}