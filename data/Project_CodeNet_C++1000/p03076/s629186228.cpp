#include <iostream>

using namespace std;

int main() {
    int *a = new int[5], ans = 0, tmp = 10;
    for (int i = 0; i < 5; i++) {
        cin >> a[i];
        ans += a[i]-a[i]%10;
        if (a[i] % 10) {
            ans += 10;
            tmp = min(tmp, a[i] % 10);
        }
    }
    ans -= 10-tmp;
    cout << ans << endl;
    return 0;
}