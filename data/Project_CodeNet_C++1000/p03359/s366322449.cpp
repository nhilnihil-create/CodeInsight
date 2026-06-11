#include <iostream>
using namespace std;

int main(void) {
    int a, b, ans;
    cin >> a >> b;
    if (a <= b) {
        ans = a;
    } else {
        ans = a-1;
    }
    cout << ans << endl;
}