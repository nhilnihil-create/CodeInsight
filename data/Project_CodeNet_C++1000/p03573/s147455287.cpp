#include <iostream>
using namespace std;

int main (void) {
    int a, b, c;
    cin >> a >> b >> c;

    int ans;
    if (a == b) {
        ans = c;
    } else if (a == c) {
        ans = b;
    } else {
        ans = a;
    }
    cout << ans << endl;
}