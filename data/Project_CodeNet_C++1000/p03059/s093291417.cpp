#include <iostream>
using namespace std;

int main() {
    double a, b, t;
    cin >> a >> b >> t;

    double i = 1.0;
    int ans = 0;
    while(a * i <= t + 0.5) {
        ans += b;
        i += 1.0;
    }
    cout << ans << endl;

    return 0;
}