#include <iostream>
using namespace std;

int main(void) {
    int a, b, x;
    cin >> a >> b >> x;

    string ans;

    if (x < a) {
        ans = "NO";
    } else {
        if ((a+b) < x) {
            ans = "NO";
        } else {
            if (b < (x-a)) {
                ans = "NO";
            } else {
                ans = "YES";
            }
        }
    }
    cout << ans << endl;
}