#include <iostream>
using namespace std;

int main (void) {
    int r, g;
    cin >> r >> g;

    // (r + next) / 2 = g
    int ans;
    ans = 2*g - r;
    cout << ans << endl;
}