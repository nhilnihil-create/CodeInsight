#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, h;
    cin >> n >> h;
    int a[n], b[n];
    for(int i = 0; i < n; i++)cin >> a[i] >> b[i];

    int amax = *max_element(a, a + n);
    sort(b, b + n);
    reverse(b, b + n);

    int damage = 0;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(amax < b[i] && damage < h) {
            damage += b[i];
            ans++;
        }
        else break;
    }

    if(damage < h) ans += (h - damage + amax - 1) / amax;
    cout << ans << endl;

    return 0;
}