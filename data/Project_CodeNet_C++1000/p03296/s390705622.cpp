#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int prev = -1, ans = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (prev == a) {
            ++ans;
            prev = -1;
        } else
            prev = a;
    }
    cout << ans << '\n';
}