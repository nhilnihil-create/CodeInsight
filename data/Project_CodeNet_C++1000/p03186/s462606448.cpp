#include <iostream>
using namespace std;

#define int long long
void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    
    int res = b;
    if (a + b + 1 >= c) {
        res += c;
    } else {
        res += a + b + 1;
    }
    cout << res << endl;
}
int32_t main () {
    
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}