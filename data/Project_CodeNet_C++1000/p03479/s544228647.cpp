#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    
    ll x, y; cin >> x >> y;
    ll ans = 1;
    while (true) {
        x *= 2;
        if (x <= y) {
            ans++;
        }
        else break;
    }
    cout << ans << endl;
    return 0;
}