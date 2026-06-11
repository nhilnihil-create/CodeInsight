#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n], k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int m = *max_element(a, a + n), dist = 2 * m;
    for (int i = 0; i < n; i++) {
        if (abs(2 * a[i] - m) < dist && a[i] != m) {
            dist = abs(2 * a[i] - m);
            k = a[i];
        }
    }
    cout << m << ' ' << k;
    return 0;
}
