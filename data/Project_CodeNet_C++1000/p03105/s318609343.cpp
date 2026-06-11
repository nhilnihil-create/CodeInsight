#include <iostream>
using namespace std;

int main () {
    int a, b, c;
    cin >> a >> b >> c;

    int ans;
    if (b/a >= c) {
        ans = c;
    } else if (b/a < c) {
        ans = b/a;
    }

    cout << ans << endl;
}