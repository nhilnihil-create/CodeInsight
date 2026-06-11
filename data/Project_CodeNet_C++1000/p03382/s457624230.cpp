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
    sort(a, a + n);
    int dist = 2 * a[n - 1];
    for (int i = 0; i < n - 1; i++) {
        if (abs(2 * a[i] - a[n - 1]) < dist) {
            dist = abs(2 * a[i] - a[n - 1]);
            k = a[i];
        }
    }
    cout << a[n - 1] << ' ' << k;
    return 0;
}
