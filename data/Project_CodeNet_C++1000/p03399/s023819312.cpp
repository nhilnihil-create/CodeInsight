#include <iostream>
using namespace std;

int main (void) {
    int a, b, c, d, ttl;
    cin >> a >> b >> c >> d;

    if (a < b) {
        ttl += a;
    } else {
        ttl += b;
    }

    if (c < d) {
        ttl += c;
    } else {
        ttl += d;
    }

    int ans = ttl;
    cout << ans << endl;
}