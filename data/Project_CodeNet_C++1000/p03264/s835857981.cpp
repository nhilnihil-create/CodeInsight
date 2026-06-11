#include <iostream>
using namespace std;

int main () {
    int k;
    cin >> k;

    int even, odd;
    if (k%2 == 0) {
        even = k/2, odd = k/2;
    } else {
        even = k/2, odd = k/2 + 1;
    }

    int ans;
    ans = even * odd;
    cout << ans << endl;
}